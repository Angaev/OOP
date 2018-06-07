#include "stdafx.h"
#include "../../../Catch/catch.hpp"
#include <string>

#include "../HTTP_URL/CUrlParsingError.h"
#include "../HTTP_URL/CHttpUrl.h"

using namespace std;

constexpr unsigned DEFALUT_HTTP_PORT = 80;
constexpr unsigned DEFALUT_HTTPS_PORT = 443;

bool IsUrlEqual(CHttpUrl const& url, string const& domain, string const& document, Protocol protocol, unsigned short port)
{
	if (url.GetDomain() != domain)
	{
		return false;
	}
	if (url.GetDocument() != document)
	{
		return false;
	}
	if (url.GetProtocol() != protocol)
	{
		return false;
	}
	if (url.GetPort() != port)
	{
		return false;
	}

	return true;
}

TEST_CASE("Can save url")
{
	CHttpUrl resource("http://google.com/search.php");
	CHECK(IsUrlEqual(resource, "google.com", "/search.php", HTTP, DEFALUT_HTTP_PORT));

	CHttpUrl resource1("https://google.com/search.php");
	CHECK(IsUrlEqual(resource1, "google.com", "/search.php", HTTPS, DEFALUT_HTTPS_PORT));
}

TEST_CASE("If save empty url, you get throw")
{
	string emptyString = {};
	CHECK_THROWS_AS(CHttpUrl(emptyString), invalid_argument);
}

TEST_CASE("If save url with empty protocol (not HTTP or HTTPS), you get throw")
{
	CHECK_THROWS_AS(CHttpUrl("some://google.com/search.php"), invalid_argument);
	CHECK_NOTHROW(CHttpUrl("Http://google.com/search.php"));
}

TEST_CASE("For http protocol save 80 port. For https protocol save 443 port")
{
	CHttpUrl resource1("http://google.com");
	CHECK(resource1.GetPort() == 80);

	CHttpUrl resource2("https://google.com");
	CHECK(resource2.GetPort() == 443);
}

TEST_CASE("Saved resource without document return /")
{
	CHttpUrl resource("https://google.com");
	CHECK(resource.GetDocument() == "/"s);
}

TEST_CASE("Saved resource with document return document")
{
	CHttpUrl resource("https://google.com/search.php");
	CHECK(resource.GetDocument() == "/search.php"s);
}

TEST_CASE("Saved resource (create as string) can return own URL")
{
	CHttpUrl resource("https://google.com/search.php");
	CHECK(resource.GetURL() == "https://google.com/search.php"s);

	CHttpUrl resource1("http://google.com/search.php");
	CHECK(resource1.GetURL() == "http://google.com/search.php"s);
}

TEST_CASE("You can create url-object, use each parameter separately (except port)")
{
	CHttpUrl resource1("google.com", "", HTTP);
	CHECK(IsUrlEqual(resource1, "google.com", "/", HTTP, DEFALUT_HTTP_PORT));
	CHECK(resource1.GetURL() == "http://google.com/"s);

	CHttpUrl resource2("google.com", "pic.php", HTTPS);
	CHECK(IsUrlEqual(resource2, "google.com", "/pic.php", HTTPS, DEFALUT_HTTPS_PORT));
	CHECK(resource2.GetURL() == "https://google.com/pic.php"s);

	CHttpUrl resource3("google.com", "/pic.php", HTTPS);
	CHECK(IsUrlEqual(resource3, "google.com", "/pic.php", HTTPS, DEFALUT_HTTPS_PORT));
	CHECK(resource3.GetURL() == "https://google.com/pic.php"s);

	SECTION("But you can't create url-object, without domain")
	{
		CHECK_THROWS_AS(CHttpUrl ("", "/pic.php", HTTPS), invalid_argument);
	}
}

TEST_CASE("You can create url-object, use each parameter separately (including port)")
{
	CHttpUrl resource1("google.com", "", HTTP, DEFALUT_HTTP_PORT);
	CHECK(IsUrlEqual(resource1, "google.com", "/", HTTP, DEFALUT_HTTP_PORT));
	CHECK(resource1.GetURL() == "http://google.com/"s);

	CHttpUrl resource2("google.com", "pic.php", HTTPS, DEFALUT_HTTPS_PORT);
	CHECK(IsUrlEqual(resource2, "google.com", "/pic.php", HTTPS, DEFALUT_HTTPS_PORT));
	CHECK(resource2.GetURL() == "https://google.com/pic.php"s);

	CHttpUrl resource3("google.com", "/pic.php", HTTPS, DEFALUT_HTTPS_PORT);
	CHECK(IsUrlEqual(resource3, "google.com", "/pic.php", HTTPS, DEFALUT_HTTPS_PORT));
	CHECK(resource3.GetURL() == "https://google.com/pic.php"s);

	SECTION("But you can't create url-object, without domain")
	{
		CHECK_THROWS_AS(CHttpUrl("", "/pic.php", HTTPS), invalid_argument);
	}

	CHttpUrl resource4("google.com", "/pic.php", HTTP, 256);
	CHECK(IsUrlEqual(resource4, "google.com", "/pic.php", HTTP, 256));
	CHECK(resource4.GetURL() == "http://google.com:256/pic.php"s);
}


TEST_CASE("Saved port must be in [0, 65536]")
{
	CHttpUrl resource1("google.com", "", HTTP, 0);
	CHECK(resource1.GetPort() == 0);
	CHECK(resource1.GetPort() != 1);

	/*SECTION("But you can't save port not in [0, 65536]")
	{
		CHECK_THROWS(CHttpUrl("google.com", "", HTTP, -1));
		CHECK_THROWS(CHttpUrl("google.com", "", HTTP, 65536 + 1));
	}*/
}