export module Time;

export struct TimeData{
	int month;
	int date;

	int hour;
	int second;
};
export void GetTime(TimeData& t);
export void GetDate(TimeData& d);

// ������� export ����
export {
      void GetTime(TimeData& t);
      void GetDate(TimeData& d);
}

// ��� �������� ���
void CheckData();
