//
// Created by kartytko on 29.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

namespace memorychunk{
    class MemoryChunk {
        public:
            MemoryChunk();
            MemoryChunk(size_t sz);
            size_t ChunkSize() const;
            int8_t *MemoryAt(size_t offset) const;
        //konstruktory parametryczne

            //Rule of five://
            //1. konstruktor kopiujący
            MemoryChunk(const MemoryChunk &xxx);
            //2. konstruktor przenoszący
            MemoryChunk(MemoryChunk &&xxx);
            //3. operator przypisania kopiujący
            MemoryChunk &operator=(const MemoryChunk &xxx);
            //4. operator przypisania przenoszący
            MemoryChunk &operator=(MemoryChunk &&xxx);
            ///5. Destruktor
            ~MemoryChunk();
        private:
            size_t size_;
            int8_t* pointer_;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
