//
// Created by kartytko on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H
#include <string>
#include <cstdint>
#include <iostream>

namespace nets{
    class SimpleUrl{
    public:
            SimpleUrl();
            SimpleUrl(std::string url);
            ~SimpleUrl();

           std::string Login() const;
           std::string Host() const;
           std::string Path() const;
           uint16_t Port() const;
           std::string Scheme() const;
           std::string Query() const;
           std::string Fragment() const;

        private:
            std::string url_;
            std::string login_;
            std::string host_;
            std::string path_;
            std::string port_;
            std::string scheme_;
            std::string query_;
            std::string fragment_;
  };
}
#endif //JIMP_EXERCISES_SIMPLEURL_H
