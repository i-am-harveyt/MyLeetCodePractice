package main

type BrowserHistory struct {
	Cur  int
	Last int
	Hist []string
}

func Constructor(homepage string) BrowserHistory {
	return BrowserHistory{
		Cur: 0, Last: 0,
		Hist: []string{homepage},
	}
}

func (this *BrowserHistory) Visit(url string) {
	this.Cur++
	if len(this.Hist) > this.Cur {
		this.Hist[this.Cur] = url
	} else {
		this.Hist = append(this.Hist, url)
	}
	this.Last = this.Cur
}

func (this *BrowserHistory) Back(steps int) string {
	if this.Cur-steps < 0 {
		this.Cur = 0
	} else {
		this.Cur -= steps
	}
	return this.Hist[this.Cur]
}

func (this *BrowserHistory) Forward(steps int) string {
	if this.Cur+steps > this.Last {
		this.Cur = this.Last
	} else {
		this.Cur += steps
	}
	return this.Hist[this.Cur]
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */
