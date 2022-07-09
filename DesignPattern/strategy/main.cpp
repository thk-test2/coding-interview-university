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
	return 0;
}