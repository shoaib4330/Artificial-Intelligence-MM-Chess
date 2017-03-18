#ifndef TEST_H
#define TEST_H


class Test
{
    public:
        Test();
        virtual ~Test();
        Test(const Test& other);
        Test& operator=(const Test& other);

    protected:

    private:
};

#endif // TEST_H
