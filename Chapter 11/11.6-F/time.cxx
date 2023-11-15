export module Time;

export struct TimeData{
	int month;
	int date;

	int hour;
	int second;
};
export void GetTime(TimeData& t);
export void GetDate(TimeData& d);

// 블록으로 export 가능
export {
      void GetTime(TimeData& t);
      void GetDate(TimeData& d);
}

// 모듈 내에서만 사용
void CheckData();
