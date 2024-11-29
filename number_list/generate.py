def generate_ascii(number):
    num_str = str(number)
    lines = [""] * 5
    for digit in num_str:
        digit_art = {
            "0": [
                " 0000 ",
                "0    0",
                "0    0",
                "0    0",
                " 0000 "
            ],
            "1": [
                "   1  ",
                "  11  ",
                "   1  ",
                "   1  ",
                " 11111"
            ],
            "2": [
                " 2222 ",
                "     2",
                " 2222 ",
                "2     ",
                " 2222 "
            ],
            "3": [
                " 3333 ",
                "     3",
                " 3333 ",
                "     3",
                " 3333 "
            ],
            "4": [
                "4   4 ",
                "4   4 ",
                " 44444",
                "    4 ",
                "    4 "
            ],
            "5": [
                " 55555",
                " 5    ",
                " 5555 ",
                "     5",
                " 5555 "
            ],
            "6": [
                "  666 ",
                " 6    ",
                " 6666 ",
                " 6   6",
                "  666 "
            ],
            "7": [
                " 77777",
                "     7",
                "    7 ",
                "   7  ",
                "  7   "
            ],
            "8": [
                "  888 ",
                " 8   8",
                "  888 ",
                " 8   8",
                "  888 "
            ],
            "9": [
                "  999 ",
                " 9   9",
                "  9999",
                "     9",
                "  999 "
            ]
        }
        for i in range(5):
            lines[i] += digit_art[digit][i] + "   "
    return "\n".join(lines)

def save_ascii_files():
    n = 1
    while n < 10000:
        filename = f"{n}.txt"
        with open(filename, "w") as f:
            f.write(generate_ascii(n))
        print(f"Saved ASCII art for {n} in {filename}")
        n *= 2  # Move to the next power of 2

if __name__ == "__main__":
    save_ascii_files()

