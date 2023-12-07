#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int H, M;
	std::cin >> H >> M;

	int Time;
	std::cin >> Time;

	int ExChangeH = H * 3600;
	int ExChangeM = M * 60;	

	int ExChangeTime = Time * 60;

	int Result = ExChangeH + ExChangeM + ExChangeTime;
	if (Result >= 86400)
	{
		Result = Result - 86400;
	}

	H = Result / 3600;
	M = (Result - (H * 3600)) / 60;

	std::cout << H << " " << M;

	return 0;
}