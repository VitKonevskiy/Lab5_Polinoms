#include "TLink.h"

template <class T>
class THeadList
{
protected:
	TLink<T>* pHead;                // указатель на голову
	TLink<T>* pFirst;               // указатель на первый
	TLink<T>* pLast;                // указатель на последний
	TLink<T>* pPred;                // указатель на предыдущий
	TLink<T>* pCurr;                // указатель на следущий
	TLink<T>* pStop;                // указатель последнего на голову
	int pos;                        // позиция текущего элемента
	int len;                        // длина списка

public:
	THeadList();
	THeadList(const THeadList& hl);
	~THeadList();

	THeadList& operator=(const THeadList &hl);
	bool operator==(const THeadList &hl);

	void InsFirst(const T& elem);    // Вставить первый элемент
	void InsCurrent(const T& elem);  // Вставить текущий элемент
	void InsLast(const T& elem);     // Вставить последний элемент
	void DelFirst();                 // Удалить первый элемент
	void DelCurrent();               // Удалить текущий элемент
	void Reset();                    // Установить pCurr на первый элемент
	void GoNext();                   // Перейти на следующий элемент
	bool IsEnd();                    // Конец списка?

};

template <class T>
THeadList<T>::THeadList()
{
	pHead = new TLink<T>;
	pStop = pHead;
	pHead->pNext = pStop;
	pFirst = pLast = pCurr = pPred = NULL;
	pos = -1;
	len = 0;
}

template <class T>
THeadList<T>::~THeadList()
{
	TLink<T>* tmp;
	if (pFirst != NULL)
	{
		pCurr = pFirst;
		while (len != 0)
		{
			pPred = pCurr;
			pCurr = pCurr->pNext;
			delete pPred;
			len--;
		}
	}
	delete pHead;
}

template <class T>
void THeadList<T>::InsFirst(const T& elem)
{
	TLink<T>* tmp = new TLink<T>(elem);
	pHead->pNext = tmp;
	if (len == 0)
	{
		tmp->pNext = pStop;
		pFirst = pLast = tmp;
	}
	else
	{
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
	pos++;
	len++;
}

template <class T>
void THeadList<T>::DelFirst()
{
	if (len != 0)
	{
		if (pCurr != pFirst)
		{
			pHead->pNext = pFirst->pNext;
			delete pFirst;
			pFirst = pHead->pNext;
			len--;
			pos--;
		}
		else
		{
			pHead->pNext = pFirst->pNext;
			delete pFirst;
			pCurr = pFirst = pHead->pNext;
			len--;
		}
	}
}

template <class T>
void THeadList<T>::InsCurrent(const T& elem)
{
	if (pCurr == pFirst)
	{
		InsFirst(elem);
		pPred = pFirst;
	}
	else
	{
		TLink<T>* tmp = new TLink<T>(elem);
		pPred->pNext = tmp;
		tmp->pNext = pCurr;
		pCurr = tmp;
		len++;
	}
}

template <class T>
void THeadList<T>::DelCurrent()
{
	if (pCurr == pFirst)
		DelFirst();
	else
	{
		pPred->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pPred->pNext;
		len--;
	}
}

template <class T>
void THeadList<T>::InsLast(const T& elem)
{
	if (len != 0)
	{
		TLink<T>* tmp = new TLink<T>(elem);
		pLast->pNext = tmp;
		tmp->pNext = pStop;
		pLast = tmp;
		len++;
	}
	else
	{
		InsFirst(elem);
	}
}

template <class T>
void THeadList<T>::Reset()
{
	pCurr = pHead->pNext;
	pPred = pHead;
	pos = 0;
}

template <class T>
void THeadList<T>::GoNext()
{
	pCurr = pCurr->pNext;
	pPred = pPred->pNext;
	pos++;
}

template <class T>
bool THeadList<T>::IsEnd()
{
	if (pCurr == pStop)
		return true;
	else
		return false;
}
template <class T>
THeadList<T>::THeadList(const THeadList& hl)
{
	pHead = new TLink<T>;
	pStop = pHead;
	pHead->pNext = pStop;
	pFirst = pLast = pCurr = pPred = NULL;
	len = 0;
	pos = 0;
	for (TLink<T>*p = hl.pFirst; p != hl.pStop; p = p->pNext)
	{
		InsLast(p->Val);
	}
}

template <class T>
THeadList<T>& THeadList<T>::operator=(const THeadList& hl)
{
	pos = 0;
	pCurr = NULL;
	while (len != 0)
		DelFirst();
	for (TLink<T>*p = hl.pFirst; p != hl.pStop; p = p->pNext)
		InsLast(p->Val);
	return *this;
}

/*template <class T>
bool THeadList<T>::operator==(const THeadList &hl)
{
	if (len != hl.len)
		return false;
	else
	{
		TLink<T>*p1 = pFirst;
		for (TLink<T>*p = hl.pFirst; p != hl.pStop; p = p->pNext)
		if (p->GetVal != p1->GetVal)
			return false;
		else
		{
			GoNext();
			hl.GoNext();
		}
		return true;
	}
}*/