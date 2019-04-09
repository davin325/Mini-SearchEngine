#include "searcher.hpp"

void Searcher::Search(std::string& searchQuery, HashMap& hashMap) {
    std::vector<std::string> parsedString;
    
    clock_t start, end;
    double  result;
    
    start = clock();
    
    parsedString = QueryParser::Parse(searchQuery);
    
    for (const std::string& str : parsedString) {
        std::vector<int> taken = hashMap.Get(str);
        this->searchedDocs.insert(this->searchedDocs.end(), taken.begin(), taken.end());
    }
    
    // TODO: searchedDocs 배열에 저장된 ID 값을 이용하여 Redis 데이터베이스에서 'TITLE(1)', 'BASIC QUALIFICATIONS(5)' 키의 값 읽어오기
    for (int i : this->searchedDocs) {
        std::cout << i << " ";
    }
    
    std::cout << "\n";
    this->searchedDocs.clear();
    
    end    = clock();
    result = (double)(end - start);
    
    printf(">>>>> (%0.4lfs)\n", result / CLOCKS_PER_SEC);
}
