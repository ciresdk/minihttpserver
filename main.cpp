#include "httpserver.h"
#include <iostream>
#include <memory>

bool handle_fun1(std::string url, std::string body, mg_connection *c, OnRspCallback rsp_callback)
{
	// do sth
	std::cout << "handle fun1" << std::endl;
	std::cout << "url: " << url << std::endl;
	std::cout << "body: " << body << std::endl;

	rsp_callback(c, "rsp1");

	return true;
}

bool handle_fun2(std::string url, std::string body, mg_connection *c, OnRspCallback rsp_callback)
{
	// do sth
	std::cout << "handle fun2" << std::endl;
	std::cout << "url: " << url << std::endl;
	std::cout << "body: " << body << std::endl;

	rsp_callback(c, "rsp2");

	return true;
}

int main(int argc, char *argv[])
{
	std::string port = "8080";
	auto httpserv = std::shared_ptr<HttpServer>(new HttpServer);
	httpserv->Init(port);
	// add handler
	httpserv->AddHandler("/api/fun1", handle_fun1);
	httpserv->AddHandler("/api/fun2", handle_fun2);
	httpserv->Start();

	return 0;
}