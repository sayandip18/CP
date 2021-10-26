bool
  valid_move (int x_len, int y_len, vector<vector<int> > &image, int x, int y,
              int nc, int pc)
  {
    
    if (x < 0 || y < 0 || x >= x_len || y >= y_len || image[x][y] != pc
        || image[x][y] == nc)
      return false;
    return true;
  }
// recursive function, if tile is valid call again with valid tile
  void
  populate (int x_len, int y_len, vector<vector<int> > &image, int x, int y,
            int nc, int pc)
  {
    // change tile to new colour
    image[x][y] = nc;
    // right
    if (valid_move (x_len, y_len, image, x + 1, y, nc, pc))
      populate (x_len, y_len, image, x + 1, y, nc, pc);
    // down
    if (valid_move (x_len, y_len, image, x, y + 1, nc, pc))
      populate (x_len, y_len, image, x, y + 1, nc, pc);
    // left
    if (valid_move (x_len, y_len, image, x - 1, y, nc, pc))
      populate (x_len, y_len, image, x - 1, y, nc, pc);
    // up
    if (valid_move (x_len, y_len, image, x, y - 1, nc, pc))
      populate (x_len, y_len, image, x, y - 1, nc, pc);
    // no valid moves, just return
    return;
  }