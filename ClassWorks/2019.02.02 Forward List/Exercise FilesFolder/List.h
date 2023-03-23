#include<string>
#include<iostream>
#include<vector>

class ItemFS abstract{
        protected:
        std::string name = "NoName";
        unsigned int size = 0;
        public:
        ItemFS(std::string n = "Noname", unsigned int s = 0): name(n), size(s){}
        virtual ~ItemFS() {}
        virtual unsigned int getSize() abstract;
        virtual void Show()abstract;
        virtual void AddItem(ItemFS* p) abstract;
};

class File : public ItemFS {
public:
    File(std::string n = "Noname", unsigned int s = 0) : ItemFS(n, s) {}

    virtual unsigned int getSize() override final { return size; }

    virtual void Show() override final { std::cout << this->name << '\n'; }

    void AddItem(ItemFS *p) {}

};

class Folder : public ItemFS {
protected:
    std::vector<ItemFS *> contents{};
public:
    Folder(std::string n = "Noname") : ItemFS(n) {}

    void AddItem(ItemFS *p) { contents.push_back(p); }

    virtual unsigned int getSize() override final {
        unsigned int Size = 0;
        for (auto x: contents)
            if (typeid(x) == typeid(File *))
                Size += x->getSize();
            else if (typeid(x) == typeid(Folder *))
                Size += x->getSize();
        return Size;
    }

    virtual void Show() override final {
        for (auto x: contents)
            if (typeid(x) == typeid(File *))
                x->Show();
            else if (typeid(x) == typeid(Folder *))
                x->Show();
    }
};