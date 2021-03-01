#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

char* GetTeam();
void SetMaze(const int** data, int width, int height);
void SetStart(int x, int y);
int x = 5, y = 5;
const int** data = new const int*[6];

int** GetMaze(int& width, int& height);
void GetNextPosition(int& xpos, int& ypos);
void SetStart(int xpos, int ypos);
void GetStart(int& xpos, int& ypos);
void SetEnd(int xpos, int ypos);
void GetEnd(int xpos, int ypos);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TeamName)
		{
			Assert::IsTrue(strcmp(GetTeam(), "Cameron Adams") == 0);
			
		}

		TEST_METHOD(SetStartCalled)
		{
			try
			{
				SetStart(1, 2);
			}
			catch(const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(GettingMaze)
		{
			for (int i = 0; i < 6; i++)
			{
				data[i] = new int[5];
				for (int j = 0; j < 5; j++)
				{
					data[i][j];
				}
				
				
			}
			SetMaze(data, x, y);
			Assert::IsTrue(GetMaze(x, y) != NULL);
		}

		TEST_METHOD(GettingNextPosition)
		{
			try
			{
				GetNextPosition(x, y);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(SettingMaze)
		{
			for (int i = 0; i < 6; i++)
			{
				data[i] = new int[5];
				for (int j = 0; j < 5; j++)
				{
					data[i][j];
				}


			}
			
			
			
			try
			{
				SetMaze(data, x, y);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		
		TEST_METHOD(GettingStart)
		{
			

			try
			{
				GetStart(x, y);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(SetEnding)
		{
			try
			{
				SetEnd(x, y);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(GettingEnd)
		{
			try
			{
				GetEnd(x, y);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}
	};
}
