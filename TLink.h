template <class T>
class TLink
{
public:
	T Val;                                 // «начение
	TLink* pNext;                          // ”казатель на след элемент

	explicit TLink(const T& _Val = T());
	TLink(const TLink& L);
	~TLink();

	T& GetVal() { return Val; }
};

template <class T>
TLink<T>::TLink(const T& _Val) 
{
	Val = _Val;
	pNext = NULL;                           // шаблон по умолчанию - "пустой" полином
}

template <class T>
TLink<T>::TLink(const TLink& L)
{
	Val = L.Val;
	pNext = L.pNext;
}

template <class T>
TLink<T>::~TLink()
{
}
