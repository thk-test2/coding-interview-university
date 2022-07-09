#include <iostream>

using namespace std;

class SearchStrategy {
public:
    virtual void search() = 0;
};

class SearchStrategyAll : public SearchStrategy {
public:
    void search() override { cout << "Search ALL" << "\n"; }
};

class SearchStrategyImage : public SearchStrategy {
public:
    void search() override { cout << "Search IMAGE" << "\n"; }
};

class SearchStrategyNews : public SearchStrategy {
public:
    void search() override { cout << "Search NEWS" << "\n"; }
};

class FindAlgorithm {
public:
    virtual void find(bool global) = 0;
};

class FindMovieAlgorithm : public FindAlgorithm {
public:
    void find(bool global) override {
        cout << "find movie" << (global ? " globally" : "") << "\n";
    }
};

class SearchFindAdapter : public SearchStrategy {
private:
    FindAlgorithm* findAlgorithm;
public:
    SearchFindAdapter(FindAlgorithm* _findAlgorithm) : findAlgorithm(_findAlgorithm) { }
    void search() {
        findAlgorithm->find(true);
    }
};

class SearchButton {
public:
    void setStrategy(SearchStrategy* _searchStrategy) {
        searchStrategy = _searchStrategy;
    }
    void onClick() { searchStrategy->search(); }

private:
    SearchStrategy* searchStrategy = new SearchStrategyAll();
};

int main() {
    SearchButton* sb = new SearchButton();
    sb->onClick();

    sb->setStrategy(new SearchStrategyImage());
    sb->onClick();

    sb->setStrategy(new SearchFindAdapter(new FindMovieAlgorithm()));
    sb->onClick();

    return 0;
}
