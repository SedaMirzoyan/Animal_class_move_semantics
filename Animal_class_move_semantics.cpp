#include <iostream>
#include <string>
#include <map>

class Animal
{
    std::string m_name;
    int m_count;

public:
    static int constr_count;


    Animal()
    {
        std::cout << __func__ << std::endl;
        m_name = " ";
        m_count = 0;

        constr_count++;
    }

    Animal(std::string s, int c)
    {
        std::cout << __func__ << std::endl;
        m_name = s;
        m_count = c;

        constr_count++;
    }

    virtual ~Animal()
    {
        std::cout << __func__ << std::endl;
    }

    Animal(const Animal& ob)
    {
        std::cout << "Copy constructor " << __func__ << std::endl;

        this->m_name = ob.m_name;
        this->m_count = ob.m_count;
    }

    Animal& operator=(const Animal& ob)
    {
        std::cout << "Animal " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_name = ob.m_name;
            this->m_count = ob.m_count;
        }
        return *this;
    }

    //move semantics
    Animal(Animal&& ob)
    {
        std::cout << "Move constructor " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_name = ob.m_name;
            this->m_count = ob.m_count;

            ob.m_name = "";
            ob.m_count = 0;
        }
    }

    Animal& operator=(Animal&& ob)
    {
        std::cout << "Animal move " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_name = ob.m_name;
            this->m_count = ob.m_count;

            ob.m_name = "";
            ob.m_count = 0;
        }
        return *this;
    }

    virtual void voice() = 0;

    virtual void move() = 0;

};

int Animal::constr_count = 0;


class Land_animals : virtual public Animal {
    bool m_is_wild; //is wild or domestic
    bool m_is_mammal; //is mammal or reptile

public:
    Land_animals()
    {
        m_is_wild = false;
        m_is_mammal = false;
        std::cout << __func__ << std::endl;
    }

    Land_animals(bool w, bool m)
    {
        m_is_wild = w;
        m_is_mammal = m;
        std::cout << __func__ << std::endl;
    }

    virtual ~Land_animals()
    {
        std::cout << __func__ << std::endl;
    }

    Land_animals(const Land_animals& ob)
    {
        std::cout << "Copy constructor " << __func__ << std::endl;

        this->m_is_wild = ob.m_is_wild;
        this->m_is_mammal = ob.m_is_mammal;

    }

    Land_animals& operator=(const Land_animals& ob)
    {
        std::cout << "Land_animals " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_is_wild = ob.m_is_wild;
            this->m_is_mammal = ob.m_is_mammal;
        }
        return *this;
    }


    //move semantics
    Land_animals(Land_animals&& ob)
    {
        std::cout << "Move constructor " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_is_wild = ob.m_is_wild;
            this->m_is_mammal = ob.m_is_mammal;

            ob.m_is_wild = false;
            ob.m_is_mammal = false;
        }
    }

    Land_animals& operator=(Land_animals&& ob)
    {
        std::cout << "Land_animals move " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_is_wild = ob.m_is_wild;
            this->m_is_mammal = ob.m_is_mammal;

            ob.m_is_wild = false;
            ob.m_is_mammal = false;
        }
        return *this;
    }


    virtual void voice() = 0;


    void move() override
    {
        if (m_is_mammal == true)
        {
            std::cout << "Mammals are running\n";
        }
        else
        {
            std::cout << "Reptiles are crawling\n";
        }
    }


    int getIsWild()const
    {
        return m_is_wild;
    }

    void setIsWild(bool w)
    {
        if (w == false)
        {
            std::cout << "Animal is domestic\n";
        }
        else
        {
            std::cout << "Animal is wild\n";
        }
        m_is_wild = w;
    }

    int getIsMammal()const
    {
        return m_is_mammal;
    }

    void setIsMammal(bool m)
    {
        if (m == false)
        {
            std::cout << "Animal is a reptile\n";
        }
        else
        {
            std::cout << "Animal is a mammal\n";
        }
        m_is_mammal = m;
    }

    void operator()()
    {
        std::cout << "Functor\n";
    }

};



class Water_animals : virtual public Animal
{
    bool m_is_fish; //or sea horse, octopus

public:
    Water_animals()
    {
        std::cout << __func__ << std::endl;

        m_is_fish = false;
    }

    Water_animals(bool f)
    {
        std::cout << __func__ << std::endl;

        m_is_fish = f;
    }

    virtual  ~Water_animals()
    {
        std::cout << __func__ << std::endl;
    }

    Water_animals(const Water_animals& ob)
    {
        std::cout << "Copy constructor " << __func__ << std::endl;

        this->m_is_fish = ob.m_is_fish;
    }

    Water_animals& operator=(const Water_animals& ob)
    {
        std::cout << "Water_animals " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_is_fish = ob.m_is_fish;
        }
        return *this;
    }

    //move semantics
    Water_animals(Water_animals&& ob)
    {
        std::cout << "Move constructor " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_is_fish = ob.m_is_fish;

            ob.m_is_fish = false;
        }
    }

    Water_animals& operator=(Water_animals&& ob)
    {
        std::cout << "Water_animals move" << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_is_fish = ob.m_is_fish;

            ob.m_is_fish = false;
        }
        return *this;
    }


    void move() override
    {
        std::cout << "All water animals are swimming\n";
    }

    virtual void voice() = 0;

    int getIfIsFish()const
    {
        return m_is_fish;
    }

    void setIfIsFish(bool f)
    {
        if (f == false)
        {
            std::cout << "It is not a fish\n";
        }
        else
        {
            std::cout << "It is a fish\n";
        }
        m_is_fish = f;
    }
};


class Amphibian : virtual public Land_animals, virtual public Water_animals
{
private:
    int m_color;

public:

    inline Amphibian() :m_color(0)
    {
        std::cout << __func__ << std::endl;
    }

    Amphibian(std::string name, int count, bool is_wild, bool is_mammal, bool is_fish, int c) : Animal(name, count), Land_animals(is_wild, is_mammal), Water_animals(is_fish), m_color(c)
    {
        std::cout << __func__ << std::endl;
    }

    ~Amphibian()
    {
        std::cout << __func__ << std::endl;
    }


    Amphibian(const Amphibian& ob)
    {
        this->m_color = ob.m_color;

        std::cout << "Copy constructor " << __func__ << std::endl;
    }

    Amphibian& operator =(const Amphibian& ob)
    {
        std::cout << "Amphibian " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_color = ob.m_color;
        }
        return *this;
    }

    //move semantics

    Amphibian(Amphibian&& ob)
    {
        std::cout << "Move constructor " << __func__ << std::endl;

        if (this != &ob)
        { 
            this->m_color = ob.m_color;
            ob.m_color = 0;
        }
    }

    Amphibian& operator =(Amphibian&& ob)
    {
        std::cout << "Amphibian move " << __func__ << std::endl;

        if (this != &ob)
        {
            this->m_color = ob.m_color;
            ob.m_color = 0;
        }
        return *this;
    }

    void voice()
    {
        std::cout << "I am amphibian\n";
    }

    void move()
    {
        std::cout << "I am swimming, jumping, climbing\n";
    }
};


int main()
{
    Animal* ptr = new Amphibian;

    ptr->voice();
    ptr->move();

    Amphibian a;
    Amphibian a_cp = a;

    a();

    std::cout << "Animal constructor was called " << Animal::constr_count << " times " << std::endl;
   
    Amphibian ob1 = std::move(Amphibian());

    delete ptr;

    return 0;
}