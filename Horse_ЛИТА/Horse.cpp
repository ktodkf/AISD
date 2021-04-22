#include <cassert>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct Position
{
	int i;
	int j;
	Position(const int i, const int j):
	i(i),
	j(j)
	{}
};

bool operator == (const Position &left, const Position &right)
{
	return left.i == right.i && left.j == right.j;
}

bool operator != (const Position& left, const Position& right)
{
	return !(left == right);
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
    int N; //размер поля
	input >> N;
	//добавить проверку открытия файла
	//добавить проверку на совпадение числа и количество значений
	vector<vector<char>> a(N, vector<char>(N));
	vector<vector<Position>> from(N, vector<Position>(N, Position(-1, -1)));
	Position start(-1, -1);
	Position end(-1, -1);
	queue<Position>queue;
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N;j++)
		{
			input >> a[i][j];
			if (a[i][j] == '@')
			{
				if (start.i == -1)
				{
					assert(start.j == -1);
					start = Position(i, j);
				}
				else
				{
					assert(end.i == -1);
					assert(end.j == -1);
					end = Position(i, j);
					a[i][j] == '.';
				}
			}
		}
	}
	assert(end.i != -1);
	assert(end.j != -1);
	queue.push(start);
	while (!queue.empty())
	{
		Position cur = queue.front();
		queue.pop();
		for (int di = -2; di <= 2; di++)
		{
			for (int dj = -2; dj <= 2; dj++)
			{
				if (di * di + dj * dj == 5)
				{
					int ni = cur.i + di;
					int nj = cur.j + dj;
					if (0 <= ni && ni<N && 0 <= nj && nj < N && a[ni][nj] == '.' && from[ni][nj].i == -1)
					{
						queue.push(Position(ni, nj));
						from[ni][nj] = cur;
					}
				}
			}
		}
	}

	if (from[end.i][end.j].i == -1)
	{
		output << "Impossible";
		return 0;
	}
	
	Position cur = end;
	do
	{
		a[cur.i][cur.j] = '@';
		cur = from[cur.i][cur.j];
	} while (cur != start);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N;j++)
		{
			output << a[i][j];
		}
		output << endl;
	}
	return 0;
}