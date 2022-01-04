/*
 *  Source code written by Gabriel Correia
*/

#include <iostream>
#include <ctime>
#include <cstring>

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

namespace Bfs = boost::filesystem;

int main ()
{
    /* Some buffers to store the current date format strings */
    char curr_time_str[20] = {0},
        file_time_str[20] = {0};
    
    std::time_t file_time, current_time = time (NULL);
    
    Bfs::path dir (".");
    Bfs::recursive_directory_iterator iter (dir), end;

    /* Retriving the current time and day */
    strftime (curr_time_str, 19, "%D", localtime (&current_time));

    BOOST_FOREACH (Bfs::path const& item, std::make_pair (iter, end)) {
        if (is_regular_file (item)) {
            /* If the current item is a file */
            file_time = Bfs::last_write_time (item);

            /*  Retrieving the current date format of the file from the last 
             *  write date
            */
            strftime (file_time_str, 19, "%D", localtime (&file_time));

            /* Compare both string buffers */
            if (!strncmp (file_time_str, curr_time_str, 19)) {
                /*  Both string buffers are equal 
                 *  (the file as been modified today :)) 
                */
                strftime (file_time_str, 19, "%T", localtime (&file_time));
                std::cout << file_time_str << ": " << item.string () << std::endl;
            }
        }
    }
}
