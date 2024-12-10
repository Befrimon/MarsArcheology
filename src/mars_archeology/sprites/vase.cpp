#include "sprites/vase.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
#include <sstream>
#include <openssl/md5.h>
#include <openssl/evp.h>

std::string md5_hash(std::string_view str)
{
    std::stringstream hash_create;
    hash_create << "echo " << str << " | md5sum > /tmp/march_vase.txt";
    system(hash_create.str().c_str());

    std::ifstream fin("/tmp/march_vase.txt", std::ios::in);
    std::string hash;
    std::getline(fin, hash);
    fin.close();
    system("rm /tmp/march_vase.txt");

    return hash;
}
std::string dec_to_bin(int num)
{
    std::string res;
    for (int i = 0; i < 4; i++)
    {
        res += std::to_string(num%2);
        num /= 2;
    }
    std::reverse(res.begin(), res.end());
    return res;
}


march::Vase::Vase(std::string_view obj_name, befry::Vector2 pos) :Sprite(obj_name, pos)
{
    texture = "";
    std::ifstream fin(std::string(befry::Core::get_texture_path()) + "vase.txt");
    while(!fin.eof())
        texture += static_cast<char>(fin.get());
    fin.close();

    Vase::set_texture(obj_name);
}
march::Vase::~Vase() = default;

void march::Vase::draw() const
{
    std::string tmp;
    std::stringstream tex_s(texture);
    for (int y = position.Y; getline(tex_s, tmp); y++)
    {
        conio::console::setCursorPosition(position.X, y);
        std::cout << tmp;
    }
    std::stringstream pat_s(pattern);
    for (int y = position.Y+4; getline(pat_s, tmp); y++)
    {
        conio::console::setCursorPosition(position.X+2, y);
        std::cout << tmp;
    }
}

void march::Vase::set_texture(std::string_view tex, bool custom_path)
{
    pattern = "";
    if (tex == "Empty")
        return;

    std::vector<char> to_dec;
    for (char i = '0'; i <= '9'; i++) to_dec.push_back(i);
    for (char i = 'a'; i < 'g'; i++) to_dec.push_back(i);
    std::string hash = md5_hash(tex);

    for (int y = 0; y < 12; y++)
    {
        auto point = std::find(to_dec.begin(), to_dec.end(), hash[2*y]);
        std::string bin = dec_to_bin(point - to_dec.begin()) + dec_to_bin(point - to_dec.begin() +1);
        for (int x = 0; x < 12; x++)
            pattern += bin[std::min(x, 11-x)] == '1' ? (x == 0 || x == 11 || y == 0 || y == 11 ? "██" : "▒▒") : "██";
        pattern += "\n";
    }
}

