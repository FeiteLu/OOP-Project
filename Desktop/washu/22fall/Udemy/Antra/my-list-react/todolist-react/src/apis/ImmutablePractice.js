import { render } from "@testing-library/react";
import { useState } from "react"


data = {
    "id": "001",
    "type": "A",
    "value": "aaaaa",
    "data:": {},
    "path": ["001"],
    "children": [
        {
            "id": "003",
            "type": "A",
            "value": "aaaaa",
            "data:": {},
            "path": ["001", "003"],
            "children": [
                {
                    "id": "002",
                    "type": "A",
                    "value": "aaaaa",
                    "data:": {},
                    "path": ["001", "003", "002"],
                    "children": []
                },
            ]
        },
        {
            "id": "004",
            "type": "A",
            "value": "aaaaa",
            "data:": {},
            "path": ["001", "004"],
            "children": [
                {
                    "id": "005",
                    "type": "A",
                    "value": "aaaaa",
                    "data:": {},
                    "path": ["001", "004", "005"],
                    "children": []
                }, {
                    "id": "005",
                    "type": "A",
                    "value": "aaaaa",
                    "data:": {},
                    "path": ["001", "004", "005"],
                    "children": [
                        {
                            "id": "002",
                            "type": "A",
                            "value": "aaaaa",
                            "data:": {},
                            "path": ["001", "004", "005", "002"],
                            "children": []
                        }
                    ]
                }
            ]
        }
    ]
}

export default immutablePractice = () => {
    [state, setState] = useState(data);

    const handleChange = () => {
        this.setState((prev) => {
            const newState = {
                ...prev,
                children: [{
                    ...prev.children[0],
                    children: [{
                        ...prev.children[0].children[0],
                        path: [
                            ...prev.children[0].children[0].slice(0, 1),
                            "004",
                            ...prev.children[0].children[0].slice(2)
                        ]

                    }],

                },
                {
                    ...prev.children[1],
                    children: [
                        ...prev.children[1].children[0],
                        {
                            ...prev.children[1].children[1],
                            children: [{
                                ...prev.children[1].children[1].children[0],
                                path: [
                                    ...prev.children[1].children[1].children[0].path.slice(0, 2),
                                    "006",
                                    ...prev.children[1].children[1].children[0].path.slice(3)
                                ]
                            }],
                        }
                    ]
                }]

            }

            return newState;
        })

    };


    return (
        <>
            <h1>immutablePractice</h1>
            <div>
                {this.state}
            </div>
            <button onClick={this.handleChange}>Change Immutable State</button>
        </>
    );



}