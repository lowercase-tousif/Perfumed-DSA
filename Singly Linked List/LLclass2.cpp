#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

// head
struct Node *head;

void insert_first(int num) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = num;
  temp->next = head;
  head = temp;
}

void insert_last(int num) {
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = num;
  newnode->next = nullptr;

  if (head == nullptr) {
    head = newnode;
  } else {
    struct Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }

    temp->next = newnode;
  }
}

void display(Node *head) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void search(Node *head, int value) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp = head;
  int flag = 0;

  while (temp != nullptr) {
    if (temp->data == value) {
      flag = 1;
      break;
    }
    temp = temp->next;
  }

  if (flag) {
    cout << "element found" << endl;
  } else {
    cout << "element not found" << endl;
  }
}

void updateLL(Node *head, int value, int index) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp = head;

  int pos = 0;

  while (temp != nullptr) {
    if (pos == index) {
      temp->data = value;
      cout << "Element found at " << pos << endl;
      cout << "Updated the element" << endl;
    }
    temp = temp->next;
    pos++;
  }
}

void lengthLL(Node *head) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp = head;

  int len = 0;

  while (temp != nullptr) {
    len++;
    temp = temp->next;
  }

  cout << "The length of the linked list is: " << len << endl;
}

Node *reverse(Node *head) {
  Node *previous = nullptr;
  Node *current = head;
  Node *following = head;

  while (current != nullptr) {
    following = following->next;
    current->next = previous;
    previous = current;
    current = following;
  }
  return previous;
}

Node *getMid(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

bool isPalindrome(Node *head) {
  if (head->next == NULL) {
    return true;
  }

  //  Find the middle element
  Node *middle = getMid(head);

  // reverse list after the middle element
  Node *temp = middle->next;
  middle->next = reverse(temp);

  // compare both halfs
  Node *head1 = head;
  Node *head2 = middle->next;

  while (head2 != NULL) {
    if (head1->data != head2->data) {
      return false;
    }
    head1 = head1->next;
    head2 = head2->next;
  }

  return true;
}

void sortLL(Node *head) {
  struct Node *i, *j;
  int temp;

  for (i = head; i != nullptr; i = i->next) {
    for (j = i->next; j != nullptr; j = j->next) {
      if (i->data > j->data) {
        swap(i->data, j->data);
      }
    }
  }

  display(head);
}

int main() {
  head = nullptr;

  string s;
  while (1) {
    cin >> s;

    if (s == "insert_first") {
      int num;
      cout << "Enter any number: ";
      cin >> num;
      insert_first(num);
    }

    else if (s == "display") {
      display(head);
    }

    else if (s == "search") {
      int value;
      cout << "Enter the value you want to search:";
      cin >> value;
      search(head, value);
    }

    else if (s == "update") {
      int index;
      cout << "Enter the index: ";
      cin >> index;

      int value;
      cout << "Enter the value: ";
      cin >> value;

      updateLL(head, value, index);
    }

    else if (s == "mid") {
      Node *mid = getMid(head);
      if (mid != nullptr) {
        cout << "Middle element is: " << mid->data << endl;
      } else {
        cout << "List is empty!" << endl;
      }
    }

    else if (s == "insert_last") {
      int value;
      cout << "Enter value: ";
      cin >> value;

      insert_last(value);
    } else if (s == "p") {
      bool v = isPalindrome(head);
      if (v) {
        cout << "Linked list is palindrome" << endl;
      } else {
        cout << "Linked list is not palindrome" << endl;
      }
    }

    else if (s == "length") {
      lengthLL(head);
    }

    else if (s == "reverse") {
      head = reverse(head);
    }

    else if (s == "sort") {
      sortLL(head);
    }

    else if (s == "exit") {
      exit(0);
    }
  }
}
