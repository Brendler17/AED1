#include <stdio.h>
#include <stdlib.h>

typedef struct Page {
  char url;
  struct Page* nextPage;
  struct Page* prevPage;
} Page;

typedef struct {
  Page* firstPage;
  Page* lastPage;
  Page* currentPage;
  int numberOfPages;
} BrowserHistory;

BrowserHistory* browserHistoryCreate(char* homepage) {
  BrowserHistory* browserHistory = (BrowserHistory*)malloc(sizeof(BrowserHistory));
  if (browserHistory == NULL) {
    printf("\nError allocating memory!\n");
    return NULL;
  }

  Page* firstPage = (Page*)malloc(sizeof(Page));
  if (firstPage == NULL) {
    printf("\nError allocating memory!\n");
    return NULL;
  }

  firstPage->url = *homepage;
  firstPage->nextPage = NULL;
  firstPage->prevPage = NULL;
  browserHistory->firstPage = firstPage;
  browserHistory->lastPage = firstPage;
  browserHistory->currentPage = firstPage;
  browserHistory->numberOfPages = 1;

  return browserHistory;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
  Page* newPage = (Page*)malloc(sizeof(Page));
  if (newPage == NULL) {
    printf("\nError allocating memory!\n");
    return;
  }

  // através do currentPage apagar todo histórico que tiver depois dele

  newPage->url = *url;
  newPage->nextPage = NULL;
  newPage->prevPage = obj->lastPage;
  obj->lastPage->nextPage = newPage;
  obj->lastPage = newPage;
  obj->currentPage = newPage;
  obj->numberOfPages++;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
  Page* currentPage;

  if (steps > obj->numberOfPages) {
    currentPage = obj->firstPage;
    return &currentPage->url;
  }

  currentPage = obj->currentPage;
  int counter = steps;

  while (counter > 0) {
    currentPage = currentPage->prevPage;
    counter--;
  }

  obj->currentPage = currentPage;

  return &currentPage->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
  if (steps > obj->numberOfPages || obj->currentPage == obj->lastPage) {
    return NULL;
  }

  Page* currentPage = obj->currentPage;
  int counter = steps;

  while (counter > 0) {
    currentPage = currentPage->nextPage;
    counter--;
  }

  obj->currentPage = currentPage;

  return &currentPage->url;
}

void browserHistoryFree(BrowserHistory* obj) {
  Page* currentPage = obj->firstPage;
  Page* aux;

  while (currentPage != NULL) {
    aux = currentPage;
    currentPage = currentPage->nextPage;
    free(aux);
  }

  obj->firstPage = NULL;
  obj->lastPage = NULL;
  obj->currentPage = NULL;
  obj->numberOfPages = 0;
}

int main() {
  char homepage[] = {"twitch.tv"};
  char url[] = {"hltv.org"};

  BrowserHistory* obj = browserHistoryCreate(homepage);

  /*
  browserHistoryVisit(obj, url);

  char* param_2 = browserHistoryBack(obj, steps);
  char* param_3 = browserHistoryForward(obj, steps);

  browserHistoryFree(obj);
  */
  return 0;
}
