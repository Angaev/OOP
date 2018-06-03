#include "stdafx.h"
#include "CHttpUrl.h"
#include <regex>


using namespace std;

constexpr unsigned MIN_PORT = 0;
constexpr unsigned MAX_PORT = 65536;
constexpr unsigned DEFALUT_HTTP_PORT = 80;
constexpr unsigned DEFALUT_HTTPS_PORT = 443;

bool IsBetween(unsigned short number, unsigned left, unsigned right)
{
	if (number <= right || number >= left)
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

CHttpUrl::CHttpUrl(std::string const & url) :
	m_url(url)
{
	if (url.empty())
	{
		CUrlParsingError("Empty URL");
	}

	smatch result;
	regex reg(R"(^(\w+):\/\/([^\s:\/]+)(?::(\d+))?(?:\/(\S*))?$)", regex::icase);

	if(!regex_search(url, result, reg))
	{
		CUrlParsingError("Incorrect URL");
	}

	m_protocol = ParseProtocol(result[1]);
	m_domain = ParseDomain(result[2]);
	m_port = ParsePort(result[3]);
	m_document = ParseDocument(result[4]);

}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol)
{
}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol, unsigned short port)
{
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

Protocol CHttpUrl::ParseProtocol(string const & rawData)
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

string CHttpUrl::ParseDomain(string const & rawData)
{
	string tempString = rawData;
	transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);

	return tempString;
}

string CHttpUrl::ParseDocument(string const & rawData)
{
	if (rawData.empty() || (rawData[0] != '/'))
	{
		return "/" + rawData;
	}
	return rawData;
}

unsigned short CHttpUrl::ParsePort(string const & rawData)
{
	if (rawData.empty())
	{
		if (m_protocol == HTTP)
		{
			return DEFALUT_HTTP_PORT;
		}
		else
		{
			return DEFALUT_HTTPS_PORT;
		}
	}
	unsigned port = stoi(rawData);
	if (IsBetween(port, MIN_PORT, MAX_PORT))
	{
		return port;
	}

	throw CUrlParsingError("Unknown port");
}

