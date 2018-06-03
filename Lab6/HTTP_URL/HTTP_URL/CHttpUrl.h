#pragma once
#include <string>
#include "CUrlParsingError.h"

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:

	CHttpUrl(std::string const& url);

	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = HTTP);

	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

	std::string GetURL() const;

	std::string GetDomain() const;

	std::string GetDocument() const;

	Protocol GetProtocol() const;

	unsigned short GetPort() const;

private:

	Protocol ParseProtocol(std::string const& rawData);
	std::string ParseDomain(std::string const& rawData);
	std::string ParseDocument(std::string const& rawData);
	unsigned short ParsePort(std::string const& rawData);
	

	std::string m_url = {};
	std::string m_document = {};
	std::string m_domain = {};
	Protocol m_protocol = HTTP;
	unsigned short m_port = 80;
};

