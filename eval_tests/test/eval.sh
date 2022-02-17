# addition by plehtika

echo "---------------------------------------------------------------------------"
echo "------------------------------ECHO OUTPUT!!!-------------------------------"
echo "---------------------------------------------------------------------------"
echo "-------------------------1 LINE WITH NL, 4 CHARS---------------------------"
echo -e "1234" | ./test_gnl stdin
echo "-------------------------1 LINE WITH NL, 8 CHARS---------------------------"
echo -e "12345678" | ./test_gnl stdin
echo "-------------------------1 LINE WITH NL, 16 CHARS--------------------------"
echo -e "1234567890abcdef" | ./test_gnl stdin
echo "-------------------------2 LINES WITH NL, 4 CHARS--------------------------"
echo -e "1234\n5678" | ./test_gnl stdin
echo "-------------------------2 LINES WITH NL, 8 CHARS--------------------------"
echo -e "12345678\n87654321" | ./test_gnl stdin
echo "-------------------------2 LINES WITH NL, 16 CHARS-------------------------"
echo -e "1234567890abcdef\n0987654321abcdef" | ./test_gnl stdin
echo "-------------------------4 LINES WITH NL, 4 CHARS--------------------------"
echo -e "1234\n5678\nabcd\nsdfg" | ./test_gnl stdin
echo "-------------------------4 LINES WITH NL, 8 CHARS--------------------------"
echo -e "12345678\n87654321\nabcdefgh\nabcd5678" | ./test_gnl stdin
echo "-------------------------4 LINES WITH NL, 16 CHARS-------------------------"
echo -e "1234567890abcdef\n0987654321abcdef\n*1234*5678*12345\nabcdef0987654321" | ./test_gnl stdin
echo "-------------------------1 LINE W/O NL, 4 CHARS----------------------------"
echo -e -n "1234" | ./test_gnl stdin
echo "-------------------------1 LINE W/O NL, 8 CHARS----------------------------"
echo -e -n "12345678" | ./test_gnl stdin
echo "-------------------------1 LINE W/O NL, 16 CHARS---------------------------"
echo -e -n "1234567890abcdef" | ./test_gnl stdin
echo "-------------------------2 LINES W/O NL, 4 CHARS---------------------------"
echo -e -n "1234\n5678" | ./test_gnl stdin
echo "-------------------------2 LINES W/O NL, 8 CHARS---------------------------"
echo -e -n "12345678\n87654321" | ./test_gnl stdin
echo "-------------------------2 LINES W/O NL, 16 CHARS--------------------------"
echo -e -n "1234567890abcdef\n0987654321abcdef" | ./test_gnl stdin
echo "-------------------------4 LINES W/O NL, 4 CHARS---------------------------"
echo -e -n "1234\n5678\nabcd\nsdfg" | ./test_gnl stdin
echo "-------------------------4 LINES W/O NL, 8 CHARS---------------------------"
echo -e -n "12345678\n87654321\nabcdefgh\nabcd5678" | ./test_gnl stdin
echo "-------------------------4 LINES W/O NL, 16 CHARS--------------------------"
echo -e -n "1234567890abcdef\n0987654321abcdef\n*1234*5678*12345\nabcdef0987654321" | ./test_gnl stdin
echo "---------------------------------------------------------------------------"
echo "------------------------------FILES!!!-------------------------------------"
echo "---------------------------------------------------------------------------"
echo "--------------------------EMPTY WITH NL------------------------------------"
./test_gnl empty_line.txt
echo "--------------------------EMPTY WITH 5 NEW LINES---------------------------"
./test_gnl empty_lines_5.txt
echo "-------------------------1 LINE WITH NL, 4 CHARS---------------------------"
./test_gnl 1_line_4_char.txt
echo "-------------------------1 LINE WITH NL, 8 CHARS---------------------------"
./test_gnl 1_line_8_char.txt
echo "-------------------------1 LINE WITH NL, 16 CHARS--------------------------"
./test_gnl 1_line_16_char.txt
echo "-------------------------2 LINES WITH NL, 4 CHARS--------------------------"
./test_gnl 2_line_4_char.txt
echo "-------------------------2 LINES WITH NL, 8 CHARS--------------------------"
./test_gnl 2_line_8_char.txt
echo "-------------------------2 LINES WITH NL, 16 CHARS-------------------------"
./test_gnl 2_line_16_char.txt
echo "-------------------------5 LINES WITH NL, 4 CHARS--------------------------"
./test_gnl 5_line_4_char.txt
echo "-------------------------5 LINES WITH NL, 8 CHARS--------------------------"
./test_gnl 5_line_8_char.txt
echo "-------------------------5 LINES WITH NL, 16 CHARS-------------------------"
./test_gnl 5_line_16_char.txt
echo "---------------------------EMPTY W/O NL------------------------------------"
./test_gnl empty
echo "-------------------------1 LINE W/O NL, 4 CHARS----------------------------"
./test_gnl no_nl_4_char.txt
echo "-------------------------1 LINE W/O NL, 8 CHARS----------------------------"
./test_gnl no_nl_8_char.txt
echo "-------------------------1 LINE W/O NL, 16 CHARS---------------------------"
./test_gnl no_nl_16_char.txt
