start.x, start.y
end.x, end.y

dxy = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
}

void dfs(int x, int y) {
	if (x == end.x && y == end.y) {
		return;
	}
	vis[x][y] = true;
	for (auto d : dxy) {
		int dx = x + d[0];
		int dy = y + d[1];
		if (valid(dx, dy)) {
			if (distance(x, y, end.x, end.y) > distance(dx, dy, end.x, end.y)) {
				path.push_back(dx, dy);
				dfs(dx, dy);
				break;
			}
		}
	}
}

Featured
Add point in work experience