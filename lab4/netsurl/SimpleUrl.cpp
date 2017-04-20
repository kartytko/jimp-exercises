//
// Created by kartytko on 25.03.17.
//

#include "SimpleUrl.h"
#include <string>
#include <cstdint>
#include <string>
#include <regex>

namespace nets{

    SimpleUrl::SimpleUrl(){
       std::string url_="";
    }
    SimpleUrl::SimpleUrl(std::string url){
        std::regex pattern {R"((\w+):(\w+)*\/{0,2}@*((\w+-*\.*)*(com|pl|info|net|org|ge)):*(\d+)*(\/(\w|\d|[^a-zA-z0-9\s\?\#])+)*\?*((\w|\d|[^a-zA-z0-9\s\?\#])+)*#*((\w|\d|[^a-zA-z0-9\s])+)*)"};
        url_ = url;
        std::string line = url_;
        std::smatch match;
        if(std::regex_match(line, match, pattern)) {
            scheme_ = match[1];
            login_ = match[2];
            host_ = match[3];
            port_ = match[6];
            path_ = match[7];
            query_ = match[9];
            fragment_ = match[11];
        }
    }
    SimpleUrl::~SimpleUrl(){};


    std::string SimpleUrl::Login() const{
        return login_;
    }
    std::string SimpleUrl::Host() const{
           return  host_;
    }
       std::string SimpleUrl::Path() const{
           std::string helping_path = path_;
          if(helping_path.size()!=0) {
              helping_path.erase(helping_path.begin());
          }
           return helping_path;
       }
       uint16_t SimpleUrl::Port() const{
          uint16_t port2;
           int port3;
          if(port_==""){
              if(scheme_=="https") {
                  port2 = 443;
              }
              if(scheme_=="http"){
                  port2=80;
              }
              if(scheme_=="ftp"){
                  port2=22;
              }
              if(scheme_=="mailto"){
                  port2=0;
              }
          }else{
              port3 = stoi(port_);
              port2 = uint16_t(port3);
          }

           return port2;
       }
       std::string SimpleUrl::Scheme() const{
           return scheme_;
       }
       std::string SimpleUrl::Query() const{
           std::string helping_query=query_;
           if(query_.size()==1 && query_[0]=='/'){
               helping_query = "";
           }
           return helping_query;
       }
       std::string SimpleUrl::Fragment() const{
           return fragment_;
       }

}