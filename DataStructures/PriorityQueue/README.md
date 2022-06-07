# Priority Queue
Priority queues are used to prioritize data. A priority queue consists of elements
organized so that the highest priority element can be ascertained efficiently. For
example, consider maintaining usage statistics about a number of servers for which
you are trying to do load balancing. As connection requests arrive, a priority
queue can be used to determine which server is best able to accommodate the
new request. In this scenario, the server with least usage is the one that gets the
highest priority because it is the best one to service the request.
## Priority Queue Example: Parcel Sorting
Most delivery services offer several options for how fast a parcel can be delivered.
Generally, the more a person is willing to pay, the faster the parcel is guaranteed
to arrive. Since large delivery services handle millions of parcels each day, priori-
tizing parcels during the sorting process is important. This is especially true when
space associated with a delivery mechanism becomes limited. In this case, parcels
with the highest priority must go first. For example, if an airplane is making only
one more trip for the day back to a central hub from a busy metropolitan area, all
parcels requiring delivery the next day had better be on board.
