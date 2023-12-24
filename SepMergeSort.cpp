//#include "header.h"
//
//using HeapType = std::pair<int, int>;
//
//struct heap {
//
//	std::vector<HeapType> h;
//	bool (*obj_comp)(const int&, const int&) = nullptr;
//
//	heap(bool comp(const int&, const int&)) {
//		obj_comp = comp;
//	}
//
//	bool comp(const HeapType &a, const HeapType &b) {
//		if (obj_comp(a.first, b.first)) {
//			return true;
//		}
//		if (obj_comp(b.first, a.first)) {
//			return false;
//		}
//		return (a.second < b.second);
//	}
//
//	void sift_up(int i) {
//		while (i != 0) {
//			if (comp(h[i], h[(i - 1) / 2])) {
//				std::swap(h[(i - 1) / 2], h[i]);
//				i = (i - 1) / 2;
//			}
//			else {
//				break;
//			}
//		}
//	}
//
//	void sift_down(int i) {
//		while (2 * i + 1 < h.size()) {
//			int next = 2 * i + 1;
//			if (2 * i + 2 < h.size() && comp(h[2 * i + 2], h[next])) {
//				next = 2 * i + 2;
//			}
//			if (comp(h[next], h[i])) {
//				std::swap(h[next], h[i]);
//				i = next;
//			}
//			else {
//				break;
//			}
//		}
//	}
//
//	void push(int V, int id) {
//		h.push_back({ V, id });
//		sift_up(h.size() - 1);
//	}
//
//	HeapType top() {
//		return h[0];
//	}
//
//	void pop() {
//		h[0] = h.back();
//		h.pop_back();
//		sift_down(0);
//	}
//
//	bool empty() {
//		return (h.size() == 0);
//	}
//
//};
//
//void stable_sep_merge_sort(int N, int* arr, bool comp(const int&, const int&)) {
//
//	std::vector<std::vector<int>> seq = { {arr[0]} };
//	heap starts(comp);
//	starts.push(arr[0], 0);
//
//	for (int i = 1; i < N; i++) {
//		int V = arr[i];
//		if (!comp(V, seq[0].back())) { // seq[0].back() <= V
//			seq[0].push_back(V);
//			continue;
//		}
//		if (comp(V, seq.back().back())) {
//			seq.push_back({ V });
//			starts.push(V, seq.size() - 1);
//			continue;
//		}
//		int l = 0;
//		int r = seq.size() - 1;
//		while (r - l > 1) {
//			int m = (l + r) / 2;
//			if (!comp(V, seq[m].back())) { //seq[m].back() <= V
//				r = m;
//			}
//			else {
//				l = m;
//			}
//		}
//		seq[r].push_back(V);
//	}
//
//	std::vector<int> poses(seq.size(), 0);
//
//	int id = 0;
//	while (!starts.empty()) {
//		int V = starts.top().first;
//		int ind_of_ar = starts.top().second;
//		starts.pop();
//		if (seq[ind_of_ar].size() != ++poses[ind_of_ar]) {
//			starts.push(seq[ind_of_ar][poses[ind_of_ar]], ind_of_ar);
//		}
//		arr[id] = V;
//		id++;
//	}
//}

#include "header.h"

using HeapType = std::pair<int, int>;

struct heap {

	std::vector<HeapType> h;
	bool (*obj_comp)(const int&, const int&) = nullptr;

	bool isStable = true;

	heap(bool comp(const int&, const int&), bool isStable) {
		obj_comp = comp;
		this->isStable = isStable;
	}

	bool stableComp(const HeapType& a, const HeapType& b) {
		if (obj_comp(a.first, b.first)) {
			return true;
		}
		if (obj_comp(b.first, a.first)) {
			return false;
		}
		return (a.second < b.second);
	}

	bool unstableComp(const HeapType& a, const HeapType& b) {
		return obj_comp(a.first, b.first);
	}

	bool comp(const HeapType& a, const HeapType& b) {
		if (isStable) {
			return stableComp(a, b);
		}
		else {
			return unstableComp(a, b);
		}
	}

	void sift_up(int i) {
		while (i != 0) {
			if (comp(h[i], h[(i - 1) / 2])) {
				std::swap(h[(i - 1) / 2], h[i]);
				i = (i - 1) / 2;
			}
			else {
				break;
			}
		}
	}

	void sift_down(int i) {
		while (2 * i + 1 < h.size()) {
			int next = 2 * i + 1;
			if (2 * i + 2 < h.size() && comp(h[2 * i + 2], h[next])) {
				next = 2 * i + 2;
			}
			if (comp(h[next], h[i])) {
				std::swap(h[next], h[i]);
				i = next;
			}
			else {
				break;
			}
		}
	}

	void push(int V, int id) {
		h.push_back({ V, id });
		sift_up(h.size() - 1);
	}

	HeapType top() {
		return h[0];
	}

	void pop() {
		h[0] = h.back();
		h.pop_back();
		sift_down(0);
	}

	bool empty() {
		return (h.size() == 0);
	}

};

void __sep_merge_sort(int N, int* arr, bool comp(const int&, const int&), bool isStable) {

	std::vector<std::vector<int>> seq = { {arr[0]} };
	heap starts(comp, isStable);
	starts.push(arr[0], 0);

	for (int i = 1; i < N; i++) {
		int V = arr[i];
		if (!comp(V, seq[0].back())) { // seq[0].back() <= V
			seq[0].push_back(V);
			continue;
		}
		if (comp(V, seq.back().back())) {
			seq.push_back({ V });
			starts.push(V, seq.size() - 1);
			continue;
		}
		int l = 0;
		int r = seq.size() - 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (!comp(V, seq[m].back())) { //seq[m].back() <= V
				r = m;
			}
			else {
				l = m;
			}
		}
		seq[r].push_back(V);
	}

	std::vector<int> poses(seq.size(), 0);

	int id = 0;
	while (!starts.empty()) {
		int V = starts.top().first;
		int ind_of_ar = starts.top().second;
		starts.pop();
		if (seq[ind_of_ar].size() != ++poses[ind_of_ar]) {
			starts.push(seq[ind_of_ar][poses[ind_of_ar]], ind_of_ar);
		}
		arr[id] = V;
		id++;
	}
}

void stable_sep_merge_sort(int N, int* arr, bool comp(const int&, const int&)) {
	__sep_merge_sort(N, arr, comp, true);
}

void unstable_sep_merge_sort(int N, int* arr, bool comp(const int&, const int&)) {
	__sep_merge_sort(N, arr, comp, false);
}