template <typename E, typename R>
//E is element type, R is result type
class EulerTour {
  protected:
    struct Result {
      R leftResult;
      R rightTesult;
      R finalResult;
    };
    typedef BinaryTree<E> BinaryTree;
    typedef typename BinaryTree::Position Position;
  protected:
    const BinaryTree* tree;
  public:
    void initialize(const BinaryTree& T) {
      tree = &T;
    }
  protected:
    int eulerTour(const Position& p) const;

    virtual void visitExternal(const Position& p) const {}
    virtual void visitLeft(const Position& p, Result& r) const {}
    virtual void visitBelow(const Position& p, Result& r) const {}
    virtual void visitRight(const Position& p, Result& r) const {}
    Result initResult() const { return Result();}
    int result(const Result& r) const { return r.finalResult;}
}

template<typename E, typename R>
int EulerTour<E, R>::eulerTour(const Position& p) const {
  Result r = initResult();
  if (p.isExternal()) {
    visitExternal(p, r);
  }
  else {
    visitLeft(p, r);
    r.leftResult == eulerTour(p.left());
    visitBelow(p, r);
    r.rightTesult == eulerTour(p.right());
    visitRight(p, r);
  }
  return result(r);
}