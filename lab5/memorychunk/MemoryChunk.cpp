//
// Created by kartytko on 29.03.17.
//

#include "MemoryChunk.h"
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
namespace memorychunk{
    MemoryChunk::MemoryChunk(){
        pointer_= nullptr;
        size_ = 0;
    }
    //konstruktory parametryczne
    MemoryChunk::MemoryChunk(size_t sz){
        size_ = sz;
        pointer_ = new int8_t[size_];
    }

    size_t MemoryChunk::ChunkSize() const{
        return size_;
    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const{
        return &pointer_[offset];
    }


    //1. konstruktor kopiujący
    MemoryChunk::MemoryChunk(const MemoryChunk &xxx){
        size_ = xxx.size_;
        pointer_ = new int8_t[size_];
        std::copy(pointer_,pointer_+size_,xxx.pointer_);
    }

    //2. konstruktor przenoszący
    MemoryChunk::MemoryChunk(MemoryChunk &&xxx) {
        size_ = 0;
        pointer_ = nullptr;
        std::swap(pointer_,xxx.pointer_);
    }

    //3. operator przypisania kopiujący
    MemoryChunk & MemoryChunk::operator=(const MemoryChunk &xxx){
        if (this == &xxx) {
            return *this;
        }
        delete[] pointer_;

        size_ = xxx.size_;
        pointer_ = new int8_t[size_];
        std::copy(pointer_,pointer_+size_-1,xxx.pointer_);
        return *this;
    }

    //4. operator przypisania przenoszący
    MemoryChunk & MemoryChunk::operator=(MemoryChunk &&xxx){
        if (this == &xxx) {
            return xxx;
        }
        delete[] pointer_;
//        size_ = 0;
        pointer_ = nullptr;
        std::swap(pointer_,xxx.pointer_);
        return xxx;
        }

    //5. Destruktor
    MemoryChunk::~MemoryChunk(){
        delete [] pointer_;
    }
}

