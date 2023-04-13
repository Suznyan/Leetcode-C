#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/*
Two strings s and t are not isomorphic if
for every index i, s[i] and t[i] first appear
in string s and t, respectively, in different
position.
*/
bool isIsomorphic(char* s, char* t) {
    if (!(s && t)) return false;
    char *spt = s, *tpt = t;
    while (*spt != '\0') {
        if (strchr(s, *spt++) - s != strchr(t, *tpt++) - t) return false;
    }
    return true;
}
int main() {}