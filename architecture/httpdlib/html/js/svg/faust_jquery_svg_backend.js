// faust_jquery_svg_backend.js

_f4u$t.make_rectangle_via_rect = function(svg, parent, rf, x, y, w, h, ops) {
  return svg.rect(parent, x, y, w, h, rf, rf, ops);
}

_f4u$t.make_rectangle_via_path = function(svg, parent, rf, x, y, w, h, ops) {
  var d = "M{0} {7}L{1} {7}C{2} {7} {2} {7} {2} {3}L{2} {4}C{2} {5} {2} {5} {1} {5}L{0} {5}C{6} {5} {6} {5} {6} {4}L{6} {3}C{6} {7} {6} {7} {0} {7}";
  d = d.format([rf + x, w - rf + x, w + x, rf + y, h - rf + y, h + y, x, y]);
  var rect = svg.path(
    parent,
    d,
    ops
  );

  return rect;
}
