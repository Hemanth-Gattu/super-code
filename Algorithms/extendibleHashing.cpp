#include <bits/stdc++.h>
#include <bitset>
using namespace std;

struct Bucket
{
    int depth, size;
    std::map<int, string> values;


    Bucket(int depth, int size)
    {
        this->depth = depth;
        this->size = size;
    }

    int insert(int key, string value)
    {
        std::map<int, string>::iterator it;
        it = values.find(key);
        if (it != values.end())
            return -1;
        if (isFull())
            return 0;
        values[key] = value;
        return 1;
    }

    int remove(int key)
    {
        std::map<int, string>::iterator it;
        it = values.find(key);
        if (it != values.end())
        {
            values.erase(it);
            return 1;
        }
        else
        {
            cout << "Cannot remove : This key does not exists" << endl;
            return 0;
        }
    }

    int update(int key, string value)
    {
        std::map<int, string>::iterator it;
        it = values.find(key);
        if (it != values.end())
        {
            values[key] = value;
            cout << "Value updated" << endl;
            return 1;
        }
        else
        {
            cout << "Cannot update : This key does not exists" << endl;
            return 0;
        }
    }

    void search(int key)
    {
        std::map<int, string>::iterator it;
        it = values.find(key);
        if (it != values.end())
        {
            cout << "Value = " << it->second << endl;
        }
        else
        {
            cout << "This key does not exists" << endl;
        }
    }

    int isFull(void)
    {
        if (values.size() == size)
            return 1;
        else
            return 0;
    }

    int isEmpty(void)
    {
        if (values.size() == 0)
            return 1;
        else
            return 0;
    }

    int getDepth(void)
    {
        return depth;
    }

    int increaseDepth(void)
    {
        depth++;
        return depth;
    }

    int decreaseDepth(void)
    {
        depth--;
        return depth;
    }

    std::map<int, string> copy(void)
    {
        std::map<int, string> temp(values.begin(), values.end());
        return temp;
    }

    void clear(void)
    {
        values.clear();
    }

    void display()
    {
        std::map<int, string>::iterator it;
        for (it = values.begin(); it != values.end(); it++)
            cout << it->first << " ";
        cout << endl;
    }
};

struct Directory
{
    int global_depth, bucket_size;
    vector<Bucket *> buckets;
    int hash(int n)
    {
        return n & ((1 << global_depth) - 1);
    }

    int pairIndex(int bucket_no, int depth)
    {
        return bucket_no ^ (1 << (depth - 1));
    }

    void grow(void)
    {
        for (int i = 0; i < 1 << global_depth; i++)
            buckets.push_back(buckets[i]);
        global_depth++;
    }

    void shrink(void)
    {
        int i, flag = 1;
        for (i = 0; i < buckets.size(); i++)
        {
            if (buckets[i]->getDepth() == global_depth)
            {
                flag = 0;
                return;
            }
        }
        global_depth--;
        for (i = 0; i < 1 << global_depth; i++)
            buckets.pop_back();
    }

    void split(int bucket_no)
    {
        int local_depth, pair_index, index_diff, dir_size, i;
        map<int, string> temp;
        map<int, string>::iterator it;

        local_depth = buckets[bucket_no]->increaseDepth();
        if (local_depth > global_depth)
            grow();
        pair_index = pairIndex(bucket_no, local_depth);
        buckets[pair_index] = new Bucket(local_depth, bucket_size);
        temp = buckets[bucket_no]->copy();
        buckets[bucket_no]->clear();
        index_diff = 1 << local_depth;
        dir_size = 1 << global_depth;
        for (i = pair_index - index_diff; i >= 0; i -= index_diff)
            buckets[i] = buckets[pair_index];
        for (i = pair_index + index_diff; i < dir_size; i += index_diff)
            buckets[i] = buckets[pair_index];
        for (it = temp.begin(); it != temp.end(); it++)
            insert((*it).first, (*it).second, 1);
    }

    void merge(int bucket_no)
    {
        int local_depth, pair_index, index_diff, dir_size, i;

        local_depth = buckets[bucket_no]->getDepth();
        pair_index = pairIndex(bucket_no, local_depth);
        index_diff = 1 << local_depth;
        dir_size = 1 << global_depth;

        if (buckets[pair_index]->getDepth() == local_depth)
        {
            buckets[pair_index]->decreaseDepth();
            delete (buckets[bucket_no]);
            buckets[bucket_no] = buckets[pair_index];
            for (i = bucket_no - index_diff; i >= 0; i -= index_diff)
                buckets[i] = buckets[pair_index];
            for (i = bucket_no + index_diff; i < dir_size; i += index_diff)
                buckets[i] = buckets[pair_index];
        }
    }

    string bucket_id(int n)
    {
        int d;
        string s;
        d = buckets[n]->getDepth();
        s = "";
        while (n > 0 && d > 0)
        {
            s = (n % 2 == 0 ? "0" : "1") + s;
            n /= 2;
            d--;
        }
        while (d > 0)
        {
            s = "0" + s;
            d--;
        }
        return s;
    }
  

    Directory(int depth, int bucket_size)
    {
        this->global_depth = depth;
        this->bucket_size = bucket_size;
        for (int i = 0; i < 1 << depth; i++)
        {
            buckets.push_back(new Bucket(depth, bucket_size));
        }
    }
    void insert(int key, string value, bool reinserted)
    {
        int bucket_no = hash(key);
        int status = buckets[bucket_no]->insert(key, value);
        if (status == 1)
        {
            if (!reinserted)
                cout << "Inserted key " << key << " in bucket " << bucket_id(bucket_no) << endl;
            else
                cout << "the key " << key << " moved to bucket the" << bucket_id(bucket_no) << endl;
        }
        else if (status == 0)
        {
            split(bucket_no);
            insert(key, value, reinserted);
        }
        else
        {
            cout << "Key " << key << " already exists" << bucket_id(bucket_no) << endl;
        }
    }

    void remove(int key, int mode)
    {
        int bucket_no = hash(key);
        if (buckets[bucket_no]->remove(key))
            cout << "The key " << key << " deleted from the bucket " << bucket_id(bucket_no) << endl;
        if (mode > 0)
        {
            if (buckets[bucket_no]->isEmpty() && buckets[bucket_no]->getDepth() > 1)
                merge(bucket_no);
        }
        if (mode > 1)
        {
            shrink();
        }
    }

    void update(int key, string value)
    {
        int bucket_no = hash(key);
        buckets[bucket_no]->update(key, value);
    }

    void search(int key)
    {
        int bucket_no = hash(key);
        cout << "Searching key " << key << " in bucket " << bucket_id(bucket_no) << endl;
        buckets[bucket_no]->search(key);
    }

    void display(bool duplicates)
    {
        int i, j, d;
        string s;
        std::set<string> shown;
        cout << "Global depth : " << global_depth << endl;
        for (i = 0; i < buckets.size(); i++)
        {
            d = buckets[i]->getDepth();
            s = bucket_id(i);
            if (duplicates || shown.find(s) == shown.end())
            {
                shown.insert(s);
                for (j = d; j <= global_depth; j++)
                    cout << " ";
                cout << s << " => ";
                buckets[i]->display();
            }
        }
    }
  
};

void menu();

string TextToBinaryString(string words)
{
    string binaryString = "";
    for (char &_char : words)
    {
        binaryString += bitset<8>(_char).to_string();
    }
    int x = 0 + (rand() % static_cast<int>(binaryString.size() - 10));
    return binaryString.substr(x, 10);
}


void menu()
{
    cout << "Select an operation :" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Update" << endl;
    cout << "4. Search" << endl;
    cout << "5. Display" << endl;
}

int main()
{
    bool show_messages, show_duplicate_buckets;
    int bucket_size, initial_global_depth;
    int key, mode;
    string choice, value;

    show_messages = 1;

    show_duplicate_buckets = 0;

    cout << "Enter the Bucket size : ";
    cin >> bucket_size;
    cout << "Enter the initial global depth : ";
    cin >> initial_global_depth;

    Directory d(initial_global_depth, bucket_size);
    cout << endl
         << "Initialized directory structure" << endl;
    menu();
    do
    {

        cout << endl;
        cin >> choice;
        if (choice == "1")
        {
            cout << "Enter the value to be inserted\n";
            cin >> value;
            string g = TextToBinaryString(value);
            key = stoi(g);
            d.insert(key, value, 0);
        }
        else if (choice == "2")
        {
            cout << "Enter the value and the mode where-\n mode: 0 = Lazy \n mode: 1 = Merge empty buckets \n mode: 2 = Merge buckets and shrink\n";
            cin >> value >> mode;
            string g = TextToBinaryString(value);
            key = stoi(g);
            d.remove(key, mode);
        }
        else if (choice == "3")
        {
            string old;
            cout << "Enter the old value and the new value to be updated seperated by space\n";
            cin >> old >> value;
            string g = TextToBinaryString(old);
            key = stoi(g);

            d.update(key, value);
        }
        else if (choice == "4")
        {
            cout << "Enter the value to search\n";
            cin >> value;
            string g = TextToBinaryString(value);
            key = stoi(g);
            d.search(key);
        }
        else if (choice == "5")
        {
            d.display(show_duplicate_buckets);
        }
    } while (choice != "0");

    return 0;
}