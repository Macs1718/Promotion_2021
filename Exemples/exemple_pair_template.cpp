#include <iostream>
#include <string>

template<typename T1, typename T2 = std::string>
struct pair
{
    T1 first;
    T2 second;

    pair( const T1& p1, const T2& p2 ) : first(p1), second(p2)
    {}
};

template<class T1, class T2> pair<T1,T2> make_pair( const T1& p1, const T2& p2)
{
    return {p1,p2};
}

int main()
{
    auto pair1 = make_pair(3, std::string("toto"));
    auto pair2 = make_pair(3, 0.1415);
    auto pair3 = pair<double, int>(4.5,2);
    auto pair4 = pair<double>(4.5,std::string("titi"));
    std::cout << "pair 1 : " << pair1.first << "," << pair1.second << std::endl;
    std::cout << "pair 2 : " << pair2.first << "," << pair2.second << std::endl;
    std::cout << "pair 3 : " << pair3.first << "," << pair3.second << std::endl;
    return 0;
}