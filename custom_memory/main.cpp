#include <cstdio>

#include "memory.h"

static constinit inline Memory memory;

auto main() -> int {
    auto _1 = memory.alloc(1);
    if ( !_1.has_value() ) {
        printf("%s", _1.error().what());
        return 1;
    }
    **_1 = std::byte(255);
    printf("[%p]\n", *_1 - 16);

    auto _2 = memory.alloc(1);
    if ( !_2.has_value() ) {
        printf("%s", _2.error().what());
        return 1;
    }
    **_2 = std::byte(255);
    *(*_2 + 1) = std::byte(255);
    printf("[%p]\n", *_2 - 16);

    memory.free(*_2);

    auto _3 = memory.alloc(1);
    if ( !_3.has_value() ) {
        printf("%s", _3.error().what());
        return 1;
    }
    **_3 = std::byte(254);
    printf("[%p]\n", *_3 - 16);

    printf("\n");
    auto block = std::addressof(memory.first_block);
    while ( block->has_next_block() ) {
        auto next_block = block->get_next_block();
        printf("%p -> %p\n", block, next_block);
        block = next_block;
    }
    printf("\n");

    for ( auto i = 0; i < 64 && i < memory.bytes.size(); ++i ) {
        printf("[%02d] [%p] %d", i, &memory.bytes[i], static_cast<int>(memory.bytes[i]));
        printf("\n");
    }

    return 0;
}
