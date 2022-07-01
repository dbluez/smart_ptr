template <typename T>
class unique_ptr
{
public:
    unique_ptr();
    unique_ptr(T *ptr);
    unique_ptr(const unique_ptr &);

private:
    T *m_ptr;
};