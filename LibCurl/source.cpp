#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <curl/curl.h>
#include <rapidjson/document.h>

using namespace std;
using namespace rapidjson;

//libCurl helper function
size_t writeFunction(void* ptr, size_t size, size_t nmemb, string* data) {
	data->append((char*)ptr, size * nmemb);
	return size * nmemb;
}

//University class
class University
{
public:
	University(const vector<string>& domains, const vector<string>& webPages, const string& name, const string& alphaTwoCode, const string& stateProvince, const string& country) noexcept :
		m_domains(domains), m_webPages(webPages), m_name(name), m_alphaTwoCode(alphaTwoCode), m_stateProvince(stateProvince), m_country(country)
	{
	}
	University(const University& rhs) = delete;
	University& operator=(const University& rhs) = delete;
	virtual ~University() noexcept { ; }

private:
	vector<string> m_domains;
	vector<string> m_webPages;
	string m_name;
	string m_alphaTwoCode;
	string m_stateProvince;
	string m_country;

public:
	const vector<string>& GetDomains() { return m_domains; }
	const vector<string>& GetWebPages() { return m_webPages; }
	const string& GetName() { return m_name; }
	const string& GetAlphaTwoCode() { return m_alphaTwoCode; }
	const string& GetStateProvince() { return m_stateProvince; }
	const string& GetCountry() { return m_country; }
};

class UnivDataHandler
{
public:
	UnivDataHandler(const string& urlIn) noexcept : m_url(urlIn) { ; }
	UnivDataHandler(const UnivDataHandler& rhs) = delete;
	UnivDataHandler& operator=(const UnivDataHandler& rhs) = delete;
	virtual ~UnivDataHandler() noexcept { ; }

private:
	//Member variables
	string m_url;
	string m_jsonData;
	vector<unique_ptr<University>> m_UniversitiesData;

public:
	void UpdateUrl(const string& urlIn) { m_url = urlIn; }

	//private methods
private:
	void RetrieveData()
	{
		CURLcode res;
		auto curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, m_url.c_str());
			curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
			curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
			curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
			curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

			string response_string;
			string header_string;
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
			curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

			res = curl_easy_perform(curl);
			if (res != CURLE_OK) {
				cout << "error: " << curl_easy_strerror(res) << endl;
				return;
			}
			else {
				m_jsonData = response_string;
			}
		}

		curl_easy_cleanup(curl);
		curl = nullptr;

		Document document;
		document.Parse(m_jsonData.c_str());
		if (!document.IsArray()) {
			cout << "The data is not in JSON format, please provide a valid url returning JSON data" << endl;
			return;
		}
	}

	void FormatData()
	{	
		m_UniversitiesData.clear();

		if (m_jsonData.size() > 0)
		{
			Document document;
			document.Parse(m_jsonData.c_str());

			for (SizeType i = 0; i < document.Size(); i++)
			{
				if (document[i].IsObject())
				{
					vector<string> domains;
					SizeType nDomains = document[i]["domains"].Size();
					for (SizeType ii = 0; ii < nDomains; ii++)
					{
						domains.push_back(document[i]["domains"][ii].IsString() ? document[i]["domains"][ii].GetString() : "NULL");
					}

					vector<string> webPages;
					SizeType nWebPages = document[i]["web_pages"].Size();
					for (SizeType jj = 0; jj < nWebPages; jj++)
					{
						webPages.push_back(document[i]["web_pages"][jj].IsString() ? document[i]["web_pages"][jj].GetString() : "NULL");
					}

					string name = document[i]["name"].IsString() ? document[i]["name"].GetString() : "NULL";
					string alphaTwoCode = document[i]["alpha_two_code"].IsString() ? document[i]["alpha_two_code"].GetString() : "NULL";
					string stateProvince = document[i]["state-province"].IsString() ? document[i]["state-province"].GetString() : "NULL";
					string country = document[i]["country"].IsString() ? document[i]["country"].GetString() : "NULL";

					//Adding individual University objects to a vector for processing later
					m_UniversitiesData.emplace_back(unique_ptr<University>(new University(domains, webPages, name, alphaTwoCode, stateProvince, country)));
				}
			}
		}
	}

public:
	//Returning string to the user, so the user can print it on console or to a text file
	string GetFormattedData()
	{
		string outStr;
		RetrieveData();
		FormatData();

		//Adding Header string
		outStr.append("Domains\t\t\tWebPages\t\t\tName\t\t\tAlphaTwoCode\t\t\tState-Province\t\t\tCountry\n\n");

		for (size_t i = 0; i < m_UniversitiesData.size(); i++)
		{
			//Adding domains column contents
			const vector<string> domains = m_UniversitiesData[i]->GetDomains();
			for (size_t i = 0; i < domains.size(); i++)
			{
				if (i != domains.size() - 1)
				{
					outStr.append(domains[i].c_str());
					outStr.append(", ");
				}

				else
				{
					outStr.append(domains[i].c_str());
					outStr.append("\t\t\t");
				}
			}

			//Adding web_pages data
			const vector<string> webPages = m_UniversitiesData[i]->GetWebPages();
			for (size_t i = 0; i < webPages.size(); i++)
			{
				if (i != webPages.size() - 1)
				{
					outStr.append(webPages[i].c_str());
					outStr.append(", ");
				}
				else
				{
					outStr.append(webPages[i].c_str());
					outStr.append("\t\t\t");
				}
			}

			//Adding names
			outStr.append(m_UniversitiesData[i]->GetName().c_str());
			outStr.append("\t\t\t");

			//Adding alpha_two_code
			outStr.append(m_UniversitiesData[i]->GetAlphaTwoCode().c_str());
			outStr.append("\t\t\t");

			//Adding state-province
			outStr.append(m_UniversitiesData[i]->GetStateProvince().c_str());
			outStr.append("\t\t\t");

			//Adding country
			outStr.append(m_UniversitiesData[i]->GetCountry().c_str());
			outStr.append("\n");
		}

		return outStr;
	}
};

int main(int argc, char** argv) {

	curl_global_init(CURL_GLOBAL_DEFAULT);

	string url = "http://universities.hipolabs.com/search?country=India";
	unique_ptr<UnivDataHandler> uPtrUnivDataHandler(new UnivDataHandler(url));

	string result = uPtrUnivDataHandler->GetFormattedData();

	//Print to console
	cout << result.c_str(); 

	string url2 = "http://universities.hipolabs.com/search?country=China";
	uPtrUnivDataHandler->UpdateUrl(url2);
	string result2 = uPtrUnivDataHandler->GetFormattedData();

	//Print to a text file
	string filePath("D:\\output.txt");
	ofstream out(filePath);
	out << result2.c_str();
	out.close();

	curl_global_cleanup();

	return 0;
}