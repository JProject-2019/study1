//[���α׷��ӽ�] ������ �簢��


unsigned long long solution(int w, int h)
{
	unsigned long long answer = 0;

	for (int i{ 1 }; i < w; i++) {
		answer += ((long long)h * i) / w;
	}


	return 2 * answer;
}