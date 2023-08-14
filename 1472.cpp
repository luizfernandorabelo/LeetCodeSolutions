class Page {
public:
    string url;
    Page* next;
    Page* previous;

    Page(string url) {
        this->url = url;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

class BrowserHistory {
public:
    Page* currentPage;

    BrowserHistory(string homepage) {
        currentPage = new Page(homepage);
    }
    
    void visit(string url) {
        Page* visitedPage = new Page(url);
        visitedPage->previous = currentPage;
        currentPage->next = visitedPage;
        currentPage = visitedPage;
    }
    
    string back(int steps) {
        while (currentPage->previous && steps) {
            currentPage = currentPage->previous;
            steps--;
        }
        return currentPage->url;
    }
    
    string forward(int steps) {
        while (currentPage->next && steps) {
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
