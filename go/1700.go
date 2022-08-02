package main

func countStudents(students []int, sandwiches []int) int {
	var stop = -1
	var eaten int = 0
	var size = len(students)
	for len(students) > 0 || len(sandwiches) > 0 {
		if sandwiches[0] == students[0] {
			students = students[1:]
			sandwiches = sandwiches[1:]
			eaten++
			stop = -1
		} else {
			students = append(students, students[0])
			students = students[1:]
			if stop == -1 {
				stop = len(students) - 1
			} else if stop == 0 {
				break
			} else {
				stop--
			}
		}
	}
	return size - eaten
}
