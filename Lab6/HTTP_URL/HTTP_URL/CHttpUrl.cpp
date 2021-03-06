#include "stdafx.h"
#include "CHttpUrl.h"
#include <regex>


using namespace std;

constexpr int MIN_PORT = 1;
constexpr int MAX_PORT = 65535;
constexpr unsigned DEFALUT_HTTP_PORT = 80;
constexpr unsigned DEFALUT_HTTPS_PORT = 443;

bool IsBetween(int number, int left, int right)
{
	if (number >= left && number <= right)
	{
		return true;
	}

	return false;
}

string ProtocolToString(Protocol const& protocol)
{
	if (protocol == HTTP)
	{
		return "http"s;
	}
	else
	{
		return "https"s;
	}
}



namespace
{
	Protocol ParseProtocol(string const & rawData)
	{
		string tempString = rawData;

		transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);


		if (tempString == "http")
		{
			return HTTP;
		}
		if (tempString == "https")
		{
			return HTTPS;
		}

		throw CUrlParsingError("Unknown protocol");
	}

	string ParseDomain(string const & rawData)
	{
		if (rawData.empty())
		{
			throw CUrlParsingError("Empty domain");
		}
		string tempString = rawData;
		transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);

		return tempString;
	}

	string ParseDocument(string const & rawData)
	{
		if (rawData.empty() || (rawData[0] != '/'))
		{
			return "/" + rawData;
		}
		return rawData;
	}


	unsigned short ParsePort(string const & rawData, Protocol protocol)
	{
		if (rawData.empty())
		{
			if (protocol == HTTP)
			{
				return DEFALUT_HTTP_PORT;
			}
			else
			{
				return DEFALUT_HTTPS_PORT;
			}
		}
		int port = stoi(rawData);
		if (IsBetween(port, MIN_PORT, MAX_PORT))
		{
			return port;
		}

		throw CUrlParsingError("Unknown port");
	}
}


CHttpUrl::CHttpUrl(std::string const & url) :
	m_url(url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Empty URL");
	}

	smatch result;
	regex reg(R"(^(\w+):\/\/([^\s:\/]+)(?::(\d+))?(?:\/(\S*))?$)", regex::icase);

	if(!regex_search(url, result, reg))
	{
		throw CUrlParsingError("Incorrect URL");
	}

	m_protocol = ParseProtocol(result[1]);
	m_domain = ParseDomain(result[2]);
	m_port = ParsePort(result[3], m_protocol);
	m_document = ParseDocument(result[4]);

}

unsigned short SetDefaultPortByProtocol(Protocol protocol)
{
	if (protocol == HTTP)
	{
		return DEFALUT_HTTP_PORT;
	}
	return DEFALUT_HTTPS_PORT;
}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol)
{
	m_domain = ParseDomain(domain);
	m_document = ParseDocument(document);
	m_protocol = protocol;
	m_port = SetDefaultPortByProtocol(m_protocol);
	m_url = ProtocolToString(m_protocol) + "://" + m_domain + m_document;
}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol, unsigned short port)
{
	m_domain = ParseDomain(domain);
	m_document = ParseDocument(document);
	m_protocol = protocol;
	m_port = ParsePort(to_string(port), m_protocol);


	m_url = ProtocolToString(m_protocol) + "://" + m_domain;

	if (!(m_port == DEFALUT_HTTP_PORT || m_port == DEFALUT_HTTPS_PORT))
	{
		m_url += ":" + to_string(m_port);
	}

	m_url += m_document;
}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}


