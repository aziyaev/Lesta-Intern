class IsEven {
public:
	static bool IsEven_BITEWISE_TASK1(int value) {
		return (value & 1) == 0;
	}

	static bool IsEven_MODULO_TASK1(int value) {
		return (value % 2) == 0;
	}
};