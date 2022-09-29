class CBuffer
{
    char* m_pBuffer;
    int m_size;
public:
    CBuffer()
    {
        m_pBuffer = NULL;
    }
    ~CBuffer()
    {
        Free();
    }
    void Allocte(int size)
    {
        m_size = size;
        m_pBuffer = new char[size];
    }
private:
    void Free()
    {
        if (m_pBuffer != NULL)
        {
            delete[] m_pBuffer;
            m_pBuffer = NULL;
        }
    }
public:
    void SaveString(const char* pText) //const
    {
        if (pText == NULL)
            return;
        Allocte(strlen(pText) + 1);
        strcpy(m_pBuffer, pText);
    }
    char* GetBuffer() const
    {
        return m_pBuffer;
    }
};

class Cmem { //ԭ�� �ڹ��������룬���������ͷ�
public:
    Cmem() :m_ptr(NULL) : size(0) {}
    Cmem(int size)
    {
        this->size = size;
        m_ptr = new int[size];  //���� :û����ɹ�զ��?
    }
    virtual ~Cmem()
    {
        delete[]m_ptr;
        m_ptr = NULL;
    }
private:
    int* m_ptr;
    int size;
};

class Cmem_ext {
public:
    Cmem_ext() :m_ptr(NULL) {}
    ~Cmem_ext()
    {
        ReleaseMem();
    }
    bool CreateMem(int size)
    {
        if (m_ptr == NULL)
        {
            m_ptr = new int[size];
            return TRUE;
        }
        else  //m_ptr ռ������䲻�ɹ�?
        {
            return FALSE;
        }
    }
    void  ReleaseMem()
    {
        if (m_ptr)
            delete[]m_ptr;
        m_ptr = NULL;
    }
private:
    int* m_ptr;
};