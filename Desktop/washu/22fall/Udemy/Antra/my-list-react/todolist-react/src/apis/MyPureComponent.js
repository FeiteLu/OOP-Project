import React from "react"

export default class myPureComponent extends React.Component {
    shallowCompare(object1, object2) {
        if (typeof object1 !== Object || typeof object2 !== Object) {
            return false;
        }

        if (Object.keys(object1).length !== Object.keys(object2).length) {
            return false;
        }

        for (let key in object1) {
            if (object1[key] !== object2[key]) {
                return false;
            }
        }

        return true;

    }

    shouldComponentUpdate(nextProps, nextState) {
        return !(this.shallowCompare(this.props, nextProps) && this.shallowCompare(this.state, nextState));
    }
}