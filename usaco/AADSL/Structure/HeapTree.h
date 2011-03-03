/*************************************************
Copyright:      No.8 Lightning Man Workgroup
Author:         Alchemist
Date    :       2011-03-03
Description:    Heap Tree
*************************************************/
#ifndef _HEAPTREE_
#define _HEAPTREE_


template <class TID, class TDATA>
class HeapTree
{
    int m_nSize;
    int m_nMAX;
    const int m_nInitMax;
    struct _NODE {
        TID id;
        TDATA data;
    };
    _NODE *m_data;

public:
    HeapTree(int nInitMax = 100);
    ~HeapTree();

    bool empty() const { return m_nSize == 0; }
    int getSize() const { return m_nSize; }

    void insert(const TID &id, const TDATA &data);
	// Remove the element with the highest priority [if the heap is not empty]
    bool removeTop();
    bool removeAll();

    bool getTopID(TID *pid) const;
    bool getTopData(TDATA *pdata) const;

	bool getData(const TID &id, TDATA *pdata) const;

	// Change the data of a node with TID = id and reformat the heap
	bool resetData(const TID &id, const TDATA &data);

private:
	// Reconstructs the heap be starting the element with index = iRoot
	void _reformatHeap(int iRoot);
};

#endif
