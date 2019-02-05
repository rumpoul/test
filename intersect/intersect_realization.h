#ifndef INTERSECT_REALIZATION_H
#define INTERSECT_REALIZATION_H

#include <set>
#include <vector>
#include <algorithm>



template <typename hh>
void output(hh& arra) {
    std::cout<<"\n******************   Array start  *************************\n\n\t";
    for(const auto &i : arra)
        std::cout << i << ' ';
    std::cout<<"\n******************   Array end    *************************\n";
}

//данный алгоритм будет работать корректно при отсутствии дубликатов внутри массивов
//мы же ищем пересечение множеств, а множество по определению не содержит дубликатов
template <typename t>
std::vector<t> intersection(std::vector<t>& arr, std::vector<t>& arr2)
{
    std::size_t maxElements = (arr.size() > arr2.size()) ? arr.size() : arr2.size();

    auto it1 = arr.begin();
    auto it2 = arr2.begin();

    auto it1_end = arr.end();
    auto it2_end = arr2.end();

    std::vector<t> result;

    std::set<t> temp;

    for( ; maxElements>0; --maxElements)
    {
        if( it1!=it1_end){
            if(temp.insert(*it1).second==false){
                result.push_back(*it1);
            }
            ++it1;
        }

        if(it2!=it2_end){
            if(temp.insert(*it2).second==false){
                result.push_back(*it2);
            }
            ++it2;
        }
    }

    result.shrink_to_fit();
    return result;
}


template <typename h>
void randomShaffle(std::vector<h>& arra, int size, int high_edge=20, int low_edge=5)
{
    int item;
    for(; arra.size() != size; ){

        item = rand()%high_edge + low_edge;

        auto iterator = std::find(arra.begin(), arra.end(), item);

        if(iterator == arra.end())
            arra.push_back(item);
    }
}


#endif // INTERSECT_REALIZATION_H
