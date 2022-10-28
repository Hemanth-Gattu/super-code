#include <bits/stdc++.h>
using namespace std;

struct linked_list
{

    int value;
    linked_list *next;
    linked_list(int value)
    {
        this->value = value;
        next = NULL;
    }
};

struct linear_hash
{

    vector<int> lsize;
    vector<pair<linked_list *, linked_list *>> p_arr;
    int ptr;
    int hashId;
    int bucketSize;
    int prev_size;
    int check2;
    int round;
    

    void clearBucket(int b)
    {
        lsize[b] = 0;
        p_arr[b] = {NULL, NULL};
        
    }
    int hashValue(int data)
    {
        
        return (data % bucketSize);
    }

    bool isfilled(int value, int bucket)
    {
        linked_list *temp = p_arr[bucket].first;
        check2 = 2;
        while (temp)
        {
            if (temp->value == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void _insert(int bucket,int value)
    {

        if (p_arr[bucket].second)
        {
            int flag1, flag2;
            p_arr[bucket].second->next = new linked_list(value);
            flag1 = 1;
            flag2 = 2;
            p_arr[bucket].second = p_arr[bucket].second->next;
            flag1 = 0;
            flag2 = 1;
        }
        else
        
            p_arr[bucket].first = p_arr[bucket].second = new linked_list(value);
        lsize[bucket] = lsize[bucket] + 1;
    }
    void createbucket()
    {
        
        p_arr.push_back({NULL, NULL});
        lsize.push_back(0);
    }

    void twice_size()
    {
        int i=0;
        while(i<lsize.size())
        
        {
            createbucket();
            i++;
        }
    }

    void insert(int value)
    {

        int bucket = hashValue(value);
        int f = 0;
        bool check = false;
        linked_list *temp = p_arr[bucket].first;
        check2 = 2;
        while (temp!=NULL)
        {
            if (temp->value == value)
                check = true;
            temp = temp->next;
        }
        if (check==true)
        {
            cout << "Key already present";
            cout<<endl;
            f = 1;
            return;
        }
        
        _insert( bucket,value);
        cout<<"The key ";
        cout<< value;
        cout<<" is inserted into bucket ";
        cout<< bucket;
        cout<<endl<<endl;
        
    }
    void _displaybuckets()
    {
        int bucket=0;
        while(bucket<lsize.size())
        
        {
            cout << "Bucket -->" << bucket << " ";
            linked_list *temp = p_arr[bucket++].first;
            while (temp != 0)
            {
                cout << " ";
                cout<< temp->value;
                temp = temp->next;
            }
            cout << "\n";
        }
    }
    void function()
    {
        int i=0;
        while(i<bucketSize)
        {
            createbucket();
            i++;
        }
    }

    linear_hash(int k)
    {
        bucketSize = k;
        round = 0;
        hashId = 0;
        ptr = 0;
        
       
    }
};

int generate(string s)
{
    int l=((int)s[0] + (int)s[1] + (int)s[3]);
    int m=((int)s[s.size() - 1] + (int)s[s.size() - 2] + (int)s[(int)s[s.size() - 3]]);
     
    return l *m ;
}

int main(int argc, char *argv[])
{
    int bucketSize_given;
    cout << "Enter the Bucket Size -";
    cout<<endl;
    cin >> bucketSize_given;
    linear_hash LH(bucketSize_given);

    LH.function();

    cout << "0.Exit"<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Display Bucketn"<<endl;
    cout<<endl;
    while (1)
    {
        cout << "Enter Option";
        cout<<endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the Key you want to insert-\n";
            string s;
            cin >> s;
            int to_insert = generate(s);
            LH.insert(to_insert);
        }
        else if (choice == 2)
        {
            LH._displaybuckets();
            cout << endl;
        }
        else if (choice == 0)
            break;
        
         
    }
    return 0;
}