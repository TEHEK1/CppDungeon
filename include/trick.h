//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_TRICK_H
#define CPPDUNGEON_TRICK_H
#ifndef TRICK_H
#define TRICK_H
namespace trick {
    constexpr int hash( const char * str, int n, unsigned int basis = 2166136261  ) {
        return n == 0 ? basis : hash( str + 1, n - 1, ( basis ^ str[ 0 ] ) * 16777619);
    }
    template< int N >
    constexpr int hash( const char ( &s )[ N ] ) {
        return hash( s, N - 1 );
    }
}
#endif // TRICK_H
#endif //CPPDUNGEON_TRICK_H
