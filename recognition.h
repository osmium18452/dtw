int get_strs_from_file(string filename, string strs[]) {
	ifstream fin(filename.c_str());
	if (!fin) {
		cout << "file read error!" << endl;
		exit(-1);
	}

	int nstr = 1;
	while (!fin.eof()) {
		getline(fin, strs[nstr++]);
	}
	fin.close();

	while ("" == strs[nstr - 1])nstr--;

	return nstr - 1;
}

float CalculateDistance(float Vector1[], float Vector2[]) {
	float ans = 0.0;
	for (int i = 1; i <= 39; i++) {
		ans += (Vector1[i] - Vector2[i]) * (Vector1[i] - Vector2[i]);
	}
	return sqrt(ans);
}

float Run_DTW(float TemplateV[][DVECTOR + 1], int NFTemplate, float TestV[][DVECTOR + 1], int NFTest) {
	float distortion;
	float distance[NFTemplate + 1][NFTest + 1];
	for (int i = 1; i <= NFTemplate; i++) {
		for (int j = 1; j <= NFTest; j++) {
			distance[i][j] = CalculateDistance(TemplateV[i], TestV[j]);
		}
	}
	for (int i = 2; i <= NFTemplate; i++) {
		distance[i][1] = distance[i - 1][1] + distance[i][1];
	}
	for (int i = 2; i <= NFTest; i++) {
		distance[1][i] = distance[1][i - 1] + distance[1][i];
	}
	for (int i = 2; i <= NFTemplate; i++) {
		for (int j = 2; j <= NFTest; j++) {
			float mini = std::min(distance[i - 1][j], distance[i][j - 1]);
			mini = std::min(distance[i - 1][j - 1], mini);
			distance[i][j] += mini;
		}
	}
	distortion = distance[NFTemplate][NFTest];
	return distortion;
}