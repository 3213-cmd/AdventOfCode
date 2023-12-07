import java.io.File

fun main() {
    var result = 0;
    val inputs : List<String> = readInputFile();
    inputs.forEach{ e -> result += (getCalibrationDigits(e))}
    println("The result is: $result")
}

fun readInputFile() : List<String> {
    return File("./input.txt").useLines {it.toList()}
}

fun getCalibrationDigits(line : String) : Int {
    var first : Int ; var last : Int;
    val digits = line.filter { it.isDigit() }
        first = digits[0].digitToInt();
    if (digits.length == 1) {
        last = first;
    }
    else {
        last = digits.last().digitToInt();
    }
    return first * 10 + last;
}
