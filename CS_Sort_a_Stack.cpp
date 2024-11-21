#include <bits/stdc++.h> 

void insertStack(stack<int>& st, int element) {
	if(st.size() == 0 || element >= st.top()) {
		st.push(element);
		return;
	}

	int topElement = st.top();
	st.pop();
	insertStack(st, element);
	st.push(topElement);
}

void sortStack(stack<int> &stack) {
	if(st.size() == 1) return;

	int topElement = st.top(); st.pop();
	sortStack(st); 

	// insert topElement again into the stack:
	insertStack(st, topElement);
	return;
}