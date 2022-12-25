#pragma once
#pragma once
//https://www.hackerrank.com/challenges/largest-rectangle/problem
#include <iostream>
#include <vector>
#include <fstream> 
#include <cmath>
#include <stack>


using namespace std;
int max_area_including_i[100000];
stack<pair<int, int>> height_positions;

int building_count;
long largestRectangle(vector<int> h) {

	max_area_including_i[0] = h[0];
	int curr_height = h[0];
	height_positions.push(make_pair(0, h[0]));

	for (int i = 1; i < building_count; i++) {
		if (h[i] > h[i - 1]) {
			if (h[i] > max_area_including_i[i - 1] + curr_height) {
				max_area_including_i[i] = h[i];
				curr_height = h[i];
			}
			else {
				max_area_including_i[i] = max_area_including_i[i - 1] + curr_height;
			}
			height_positions.push(make_pair(i, h[i]));
		}
		else {
			for (int i = 0; !height_positions.empty(); i++) {
				pair<int, int> this_position = height_positions.top();
				if (this_position.second <= h[i]) {

				}
			}
		}
	}
	return 0;
}

void run() {
	vector<int> building_heights;
	cin >> building_count;
	int temp;
	for (int i = 0; i < building_count; i++) {
		cin >> temp;
		building_heights.push_back(temp);
	}
	largestRectangle(building_heights);
}

